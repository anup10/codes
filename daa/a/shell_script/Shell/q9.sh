#!/bin/bash

num=$(ls | wc -l)
ls > res.txt
 
echo -n "Enter the folder name: "
read folder
file=$folder.txt
 
i=0
n=0
for line in $(cat res.txt) 
do
	if [ $line = $folder ]
	then
		break
	elif [ $line = $file ]
	then
		n=1
		break
	fi
	i=`expr $i + 1`
done

if [ $i -eq $num -a $n -eq 0 ]
then
	mkdir $folder
elif [ $n -eq 1 ]
then
	rm $file
	mkdir $folder
elif [ $i -lt $num -a $n -eq 0 ]
then 
	echo "ERROR:Folder Exists "
fi
