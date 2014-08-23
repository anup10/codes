#!/bin/sh

x=$(ls)
for line in $x
do
	if [ -f $line ]
	then
	y=`wc -c < $line`
	echo $y
	if [ $y -eq 0 ]
	then
		rm $line
	fi
	fi
done

