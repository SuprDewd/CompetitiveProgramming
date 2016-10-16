#!/usr/bin/env bash

DIR=$(readlink -f $(dirname $0))
DIR2=$(readlink -f $(dirname $1))
TEST=$(basename ${1%.*})

cd $DIR2
rm -f $DIR/tmp.cpp
cp $DIR/../code/header.cpp $DIR/tmp.cpp
echo "" >> $DIR/tmp.cpp
echo "#include \"$DIR2/$TEST.cpp\"" >> $DIR/tmp.cpp
cat $DIR/test_header.cpp >> $DIR/tmp.cpp
echo "" >> $DIR/tmp.cpp
echo "#line 1 \"$DIR2/$TEST.test.cpp\"" >> $DIR/tmp.cpp
cat "$DIR2/$TEST.test.cpp" >> $DIR/tmp.cpp
echo "" >> $DIR/tmp.cpp
cat $DIR/test_footer.cpp >> $DIR/tmp.cpp
set -e
${CXX-g++} $DIR/tmp.cpp -Wall -Wshadow -Wpedantic -Wno-long-long -std=c++11 -g -o $DIR/tmp.exe
$DIR/tmp.exe
