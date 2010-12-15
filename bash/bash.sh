#!/bin/bash
echo hello world!
for i in $(seq 1 10)
do
    echo -n "file${i} ";
    touch file${i};
done
for file in file1 file2 file3 file4
do
    echo $file
    mv $file $file.c
done
