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
git add .
read -e MSG
git commit -a -m "$MSG:-No-Information"
echo -n "Wheter push it to remote master(Y/n)"
read CHOICE
if [ "$CHOICE:-y" = "y" ]
then
    echo pushing...........
    git push
else
    echo cancelled
fi
    
