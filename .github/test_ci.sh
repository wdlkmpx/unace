#!/bin/sh

if [ "$1" = "freebsd" ] ; then
    #export REPO_AUTOUPDATE=NO
    #pkg install -y ncurses
    printf ""
    exit $?
fi

if [ "$1" = "macos" ] ; then
    export HOMEBREW_NO_AUTO_UPDATE=1
    ## macOS already provides ncurses by default
    #brew install ncurses
    exit $?
fi

# ============================================

cmdecho()
{
    echo "---------------------"
    echo "# $@"
    echo "---------------------"
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

uname -a

#export CFLAGS="-DDEBUG_W_ENDIAN"

#cmdecho ./configure  || exit_error
#cmdecho make         || exit_error
#cmdecho make check   || exit_error
#cmdecho make install || exit_error
./run-tests.sh || exit_error
