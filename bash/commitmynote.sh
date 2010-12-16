#!/bin/bash

if [ `id -u` = "0" ]
then
    echo This script must not be run in root. 1>&2
    exit 1
fi

cd ~/Documents/C_practice/
rm *.swp
echo junkfile has been removed!
echo
echo adding files.....
git add .
echo added
echo -n Enter commit message:
read -e MSG
git commit -a -m "${MSG:-No-Information}"
echo -n "Wheter push it to remote master(Y/n)"
read CHOICE
if [ "${CHOICE:-y}" = "y" ]
then
    echo pushing...........
    git push
    echo Git Push Finished!
else
    echo cancelled
fi
    
