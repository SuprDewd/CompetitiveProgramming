#/usr/bin/env bash

DIR=$(readlink -f $(dirname $0))
set -e

for i in $(find $DIR/../code -name "*.test.cpp")
do
	cur="${i%.test.cpp}.cpp"
	echo $cur
	$DIR/run_test.sh $cur
done
