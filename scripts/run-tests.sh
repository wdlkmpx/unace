#!/bin/sh
# Public domain

scriptdir=$(dirname "$0")
scriptdir=$(readlink -f "$scriptdir")
w_system=$(uname -s)

if [ -z "$RUN_TESTS_CFG" ] ; then
    RUN_TESTS_CFG=${scriptdir}/run-tests.cfg
fi
if [ "$1" = "-cfg" ] ; then
    RUN_TESTS_CFG=$(realpath "$2")
    shift 2
fi
if [ -z "$RUN_TESTS_CFG" ] ; then
    help 1
fi

. ${RUN_TESTS_CFG} || exit 1

REBUILD=no
case $1 in
    -rebuild) REBUILD=yes ;;
    -run)     REBUILD=no ;;
    #*) help 0 ;;
esac

export CFLAGS="-DW_MTRACE -g -O0 -ggdb3 -Wextra -Wno-unused-parameter -Wno-missing-field-initializers"

# ===========================================================================
# Functions

. ${scriptdir}/0functions.sh

set_checksum_app
set_download_app

set_wine()
{
    wine=''
    if [ "${w_system}" = "Linux" ] ; then
        wine='wine'
        if command -v wine >/dev/null ; then
            echo "WINE is not installed, cannot test .exe binaries..."
            exit 1
        fi
    fi
}


check_sums_from_file()
{
	chksum_file="$1"
	logfile="$2"
	if test -z "$CHKSUM_APP" || test -z "$chksum_file" ; then
		return 0 # ok
	fi
	echo "------------------------------" >>${logfile}
 	if [ "$CHKSUM_APP" = "$CHKSUM_BSD" ] ; then
		# --BSD--
		while read sum file
		do
			filesum=$($CHKSUM_APP -q "$file")
			if [ "$sum" != "$filesum" ] ; then
				echo "${file}: FAILED"  >>${logfile}
				echo "*** checksum failed. stopped" >>${logfile}
				return 1 #error
			fi
		done < ${chksum_file}
	else
		# --GNU--
		if ! ${CHKSUM_APP} -c ${chksum_file} >>${logfile} 2>&1 ; then
			return 1 #error
		fi
	fi
	echo "------------------------------" >>${logfile}
	return 0 # ok
}


check_dirs_from_dirlist_file()
{
	dirlist_file="$1"
	logfile="$2"
	if [ -z "$dirlist_file" ] ; then
		return 0
	fi
	wret=0
	echo "checking dirs..." >>${logfile}
	while read dir ; do
		if [ ! -d "$dir" ] ; then
			wret=1
			echo "[ERROR] $dir is missing" >>${logfile}
		fi
	done < ${dirlist_file}
	return ${wret}
}


gdbargs=''
if command -v gdb >/dev/null ; then
    gdbargs='gdb --args'
fi

ERROR_LOG_FILES=''

run_test()
{
    unset CHKFILE DIRFILE LOGFILE
    if [ -z "$TEST_FILE" ] ; then
        echo "** a \$TEST_FILE is required for run_test()"
        echo "** fix the script!"
        exit 1
    fi
    #--
    if [ -n "$TEST_FILE_URL" ] ; then
        download_file "$TEST_FILE_URL" "$TEST_FILE"
        unset TEST_FILE_URL
    fi
    #--
    if ! [ -f "$TEST_FILE" ] ; then
        echo "** $TEST_FILE doesn't exist .. fix the script"
        exit 1
    fi
    TEST_FILE_NAME=$(basename "$TEST_FILE")
    if [ -f ${TEST_FILE}.${CHKSUM_TYPE} ] ; then
        CHKFILE=${TEST_FILE}.${CHKSUM_TYPE}
    fi
    if [ -f ${TEST_FILE}.dirs ] ; then
        DIRFILE=${TEST_FILE}.dirs
    fi
    LOGFILE=${TESTDIR}/${TEST_FILE_NAME}.log
    #--
    test_error=
    #--
    printf "* [test] ${TEST_FILE_NAME}: "
    echo >${LOGFILE}
    echo "------------------------------------" >>${LOGFILE}
    echo "${gdbargs} $@" >>${LOGFILE}
    echo "------------------------------------" >>${LOGFILE}
    if [ "$TEST_USE_SUBDIR" = "yes" ] ; then
        xcurdirx=$(pwd)
        rm -rf ${TESTDIR}/${TEST_FILE_NAME}_test
        mkdir -p ${TESTDIR}/${TEST_FILE_NAME}_test
        cd ${TESTDIR}/${TEST_FILE_NAME}_test
    fi
    "$@" >>${LOGFILE} 2>&1
    exit_code=$?
    if [ "$TEST_RUN_GDB_ON_SEGFAULT" = "yes" ] ; then
        # segfault? try to get backtrace
        case ${exit_code} in 132|133|134|135|136|137|138|139)
            echo "------------------------------------" >>${LOGFILE}
            echo "${scriptdir}/backtrace.sh -run ${@}" >>${LOGFILE}
            echo "------------------------------------" >>${LOGFILE}
            ${scriptdir}/backtrace.sh -run ${@} >>${LOGFILE} 2>&1
            ;;
        esac
    fi
    if [ -z "$TEST_EXIT_CODE" ] ; then
        TEST_EXIT_CODE=0 # default
    fi
    case ${TEST_EXIT_CODE} in
        !*)
            if [ "!${exit_code}" = "${TEST_EXIT_CODE}" ] ; then
                echo "[ERROR] Exit code  = ${exit_code}" >>${LOGFILE}
                test_error=1
            fi
            ;;
        *)
            if [ "${exit_code}" = "${TEST_EXIT_CODE}" ] ; then
                echo "[OK] Exit code = ${exit_code}" >>${LOGFILE}
            else
                echo "[ERROR] Exit code  = ${exit_code}" >>${LOGFILE}
                echo "Expected exit code = ${TEST_EXIT_CODE}" >>${LOGFILE}
                test_error=1
            fi
            ;;
    esac
    if [ -n "$TEST_ERROR_FILE" ] ; then
        if [ -e "$TEST_ERROR_FILE" ] ; then
            echo "[ERROR] $TEST_ERROR_FILE exists" >>${LOGFILE}
            test_error=1
        fi
    fi
    if ! check_sums_from_file "${CHKFILE}" "${LOGFILE}" ; then
        test_error=1
    fi
    if ! check_dirs_from_dirlist_file "${DIRFILE}" "${LOGFILE}" ; then
        test_error=1
    fi
    if [ -z "$test_error" ] ; then
        echo "OK"
    else
        echo "ERROR"
        ERROR_LOG_FILES="$ERROR_LOG_FILES ${LOGFILE}"
    fi
    if [ "$TEST_USE_SUBDIR" = "yes" ] ; then
        cd "${xcurdirx}"
    fi
    unset TEST_FILE TEST_ERROR_FILE TEST_EXIT_CODE
}

# ===========================================================================

if [ -f autogen.sh ] && [ ! -f configure ] ; then
    ./autogen.sh
fi

if [ -f configure ] && [ ! -f config.log ] ; then
    ./configure ${configure_opts}
fi

if [ -f Makefile ] ; then
    if [ "$REBUILD" = "yes" ] ; then
        ${make_clean}
    fi
    ${make_cmd}
fi

if [ -f ${app}.exe ] ; then # .exe binary
    set_wine
    app="${wine} ${app}"
fi

if ! test -f ${app} ; then
    echo "$app not found"
    exit 1
fi

# basic check
check_app_help ${help_ret_code} "${app} ${help_param}"

# ===========================================================================

echo
appname=$(basename "$app")
TESTDIR=$(pwd)/0runtests_${appname}
rm -rf "${TESTDIR}"
mkdir -p "${TESTDIR}"
cd ${TESTDIR}

run_tests

# ===========================================================================

ret=0

if [ -n "$(echo $ERROR_LOG_FILES)" ] ; then
    ret=1
    if [ -n "$VERBOSE_ERRORS" ] ; then
        cat $ERROR_LOG_FILES
    fi
fi

printf "\n Logs are in $TESTDIR\n"
echo "   (that dir is deleted and created everytime the tests are run)"
echo

exit $ret
