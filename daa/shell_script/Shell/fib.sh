#!/bin/bash

echo -n "Enter the number: "
read num

i=0
while [ $i -lt $num ]
do
	if [ $i -eq 0 ]
	then
		arr[0]=0
	elif [ $i -eq 1 ]
	then
		arr[1]=1
	else
		temp1=${arr[`expr $i - 1`]}
		temp2=${arr[`expr $i - 2`]}
		arr[i]=`expr $temp1 + $temp2`
	fi
	i=`expr $i + 1`
done

echo "Fibonacci: ${arr[`expr $num - 1`]}"
