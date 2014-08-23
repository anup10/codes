#!/bin/sh

x=1
until [ $x -eq 11 ]
do
	echo $x
	x=`expr $x + 1`
done

