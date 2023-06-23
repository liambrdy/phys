#!/bin/sh

set -xe

export PKG_CONFIG_PATH="$HOME/opt/raylib/lib/pkgconfig/"

LIB_NAMES="raylib"
CFLAGS="-Wall -Wextra `pkg-config --cflags $LIB_NAMES`"
LIBS="-lm `pkg-config --libs $LIB_NAMES`"

clang $CFLAGS -o main main.cpp $LIBS