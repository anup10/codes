#!/bin/bash

echo -n "Enter the folder name: "
read folder
num=$(ls -a $folder | grep '^\.' | wc -l)
ls -a $folder | grep '^\.' > res.txt
 

