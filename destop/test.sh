#!/bin/bash

total=1
success=0
pwd=`pwd`

echo [Desktop Entry] > test.desktop
echo Name=Hello >> test.desktop

output=`LANG=C ./build/freedesktop -d $pwd/test.desktop -n`
if [ $output = "Hello" ] ;then
	success=`expr $success + 1`
fi

rm -f test.desktop
echo success: $success, fail: `expr $total - $success`
