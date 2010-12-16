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
cd $1
file="a.b.c"
f=`echo $file|awk -F'.' '{ print $1 $2 $3 }' `
echo $f

for fcc in `ls *.c`
do
    rr=`echo $fcc|awk -F'.' '{ print $1 }' `
mv $fcc $rr
done

for fccc in `ls *.c.c`
do
    rrr=`echo $fcc|awk -F'.' '{ print $1 "." $2 }' `
    mv $fccc $rrr
done
    
