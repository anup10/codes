#!/bin/bash

for i in 1 2 3
do
	if [ $i -eq 1 ]
	then
		for j in 2 3
		do
			temp1=`expr $i + $j`
			temp=`expr 6 - $temp1`
			echo "$i $j $temp"
		done
	fi
	if [ $i -eq 2 ]
	then
		for j in  3 1
		do
			temp1=`expr $i + $j`
			temp=`expr 6 - $temp1`
			echo "$i $j $temp"
		done
	fi
	if [ $i -eq 3 ]
	then
		for j in 1 2
		do
			temp1=`expr $i + $j`
			temp=`expr 6 - $temp1`
			echo "$i $j $temp"
		done
	fi
done
