#!/bin/bash

echo -n "Enter the number: "
read num
facto=1
while [ $num -gt 0 ] 
do
	facto=`expr $facto \* $num`
	num=`expr $num - 1`
done

echo "Factorial: "$facto
