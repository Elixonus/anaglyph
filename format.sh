#!/bin/bash
filelist=$(
	find . -type f -name "*.c" &&
	find . -type f -name "*.h" &&
	find . -type f -name "*.sh" &&
	echo "LICENSE"
)
dos2unix $filelist
for file in $filelist
do
	iconv -t US-ASCII "$file" | sponge "$file"
done
