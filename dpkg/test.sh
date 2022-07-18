#!/bin/bash

total=1
fail=0

# bash，检查文件
mv /usr/share/locale/sr/LC_MESSAGES/tar.mo  /usr/share/locale/sr/LC_MESSAGES/tar.mo.bak
./build/pkgverify tar > log1
echo /usr/share/locale/sr/LC_MESSAGES/tar.mo > log2
diff log1 log2 > /dev/null
if [ $? != "0" ] ;then
	fail=`expr $fail + 1`
fi
rm log1 log2
mv /usr/share/locale/sr/LC_MESSAGES/tar.mo.bak /usr/share/locale/sr/LC_MESSAGES/tar.mo

echo success: `expr $total - $fail`, fail: $fail
