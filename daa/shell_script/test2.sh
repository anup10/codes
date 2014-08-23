#!/bin/sh

x=`expr $1 % 2`
echo "$x"
if	[ $x -eq 0 ]
then 
	echo "no. is even"
else
	echo "no. is odd"
fi

