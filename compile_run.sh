#!/bin/bash

BUILD_DIR=build
mkdir -p $BUILD_DIR

FILE=$1
EXE=`echo "$FILE" | cut -d'.' -f1`
EXE_PATH=$BUILD_DIR/$EXE
echo $FILE $EXE
shift
ARGS=$@
g++ -std=c++14 -o $EXE_PATH $FILE && ./$EXE_PATH $ARGS
