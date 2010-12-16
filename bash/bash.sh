#!/bin/bash
#echo hello world!
#for i in $(seq 1 10)
#do
    #echo -n "file${i} ";
    #touch file${i};
#done
#for file in file1 file2 file3 file4
#do
    #echo $file
    #mv $file $file.c
#done
#cd bash/
#filelist=`ls`
#myname=`ls *.sh`
#for file in $filelist
#do
    #echo $myname
    #echo $file
    #if [ $file!=$myname ]
    #then
        #mv $file $file.c 
    #fi
#done
#cd $1
#echo $0 $1 $2 $3
#file="a.b.c"
#f=`echo $file|awk -F'.' '{ print $1 $2 $3 }' `
#echo $f
#for fcc in `ls *.c`
#do
    #rr=`echo $fcc|awk -F'.' '{ print $1 }' `
#mv $fcc $rr
#done
#echo $1.c
#if [ -f a.c ]
#then
    #mv a.c a
#elif [ -f a ]
#then
    #mv a a.c
#fi
#if [ -d dir1 ]
#then
    #echo already exists.
#else
    #mkdir dir1
#fi
#if [ -d dir2 ]
#then
    #rm -rf dir2
    #echo removed!
#fi
#if [ "$(id -u)" = "0" ]; then
   #echo "This script must NOT be run as root, exit" 1>&2
   #exit 1
#fi
echo -n "Want to say hello(Y/n): "
read Choice
if [ "${Choice:-y}" = "y" ];then
    echo hello
fi
