#!/bin/sh

case $1 in
    debug|-debug)
        RUN_TEST_SCRIPT_DIRECTLY=1
        ;;
    installpkg_alpine)
        shift
        set -x
        apk add --no-cache ${@}
        exit $?
        ;;
    installpkg_deb)
        shift
        set -ex
        apt update
        apt upgrade -y
        apt-get install -y ${@}
        exit $?
        ;;
    installpkg_macos)
        shift
        set -x
        export HOMEBREW_NO_AUTO_UPDATE=1
        brew install ${@}
        exit $?
        ;;
    installpkg_freebsd)
        shift
        set -x
        #export REPO_AUTOUPDATE=NO
        pkg install -y ${@}
        exit $?
        ;;
esac

w_system=$(uname -s)

# ============================================

cmdecho()
{
    echo
    echo "#################################"
    echo "# $@"
    echo "#################################"
    "$@"
}

print_config_log()
{
    for i in config.h config.log config.mk
    do
        echo "
===============================
	$i
===============================
"
        cat ${i}
    done
}

exit_error()
{
    print_config_log
    exit 1
}

# ============================================
# print some system info

uname -a
echo
if command -v cc 1>/dev/null 2>&1 ; then
    cc --version 2>/dev/null
elif command -v gcc 1>/dev/null 2>&1 ; then
    gcc --version 2>/dev/null
fi
#echo
#id

case "$w_system" in
    Darwin|FreeBSD)
        sysctl kern.coredump
        sysctl kern.corefile
        ;;
esac

# ============================================

#export CFLAGS="-DDEBUG_W_ENDIAN"
export VERBOSE_ERRORS='yes' # the test script read this
#export PRINT_SUM_ON_ERROR='yes'
#exprt DOWNLOAD_IS_REQUIRED='yes'

    #cmdecho ./configure  || exit_error
    #cmdecho make         || exit_error
    #cmdecho make check   || exit_error
    ##cmdecho make install || exit_error

# assuming we're testing a compiled binary that's built with -02 (optimizations)
cmdecho ./scripts/run-tests.sh -rebuild
if [ $? -ne 0 ] ; then
    if [ "$w_system" = "Darwin" ] ; then
        # macOS is a hostile environment, just end here
        exit_error
    fi
    if grep -q ' -O2' config.log ; then
        echo
        echo "################################################################"  
        echo "   Testing with extra debug symbols and without optimizations   "
        echo "################################################################"
        echo
        # one or tests failed, segfaults?
        # run with extra debug symbols and without optimizations
        # if there are no segfaults, the optimizations are causing the segfaults
        cmdecho ./scripts/run-tests.sh -debug
    fi
    exit_error
fi


