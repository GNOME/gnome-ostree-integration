AC_PREREQ([2.63])
AC_INIT([gnome-ostree-integration], [2012.4], [walters@verbum.org], [gnome-ostree-integration], [https://live.gnome.org/OSTree/GnomeOSTree])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

OS_NAME="GNOME-OSTree"
OS_ID=$PACKAGE_TARNAME
OS_VERSION=3.6
OS_PRETTY_NAME="$OS_NAME ($OS_VERSION, OE-Core edison, $PACKAGE_VERSION)"

AC_SUBST([OS_NAME])
AC_SUBST([OS_ID])
AC_SUBST([OS_VERSION])
AC_SUBST([OS_PRETTY_NAME])

AM_INIT_AUTOMAKE([1.11 -Wno-portability foreign no-define tar-ustar no-dist-gzip dist-xz])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

AM_PATH_PYTHON([2.6])

AC_CONFIG_FILES([
Makefile
])
AC_OUTPUT

echo "
    GNOME-OSTree integration $VERSION
"
