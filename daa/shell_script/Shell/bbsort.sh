#!/bin/bash

echo -n "Enter the size: "
read size
echo -n "Enter the numbers: "

i=0
while [ $i -lt $size ]
do
	read arr[i]
	i=`expr $i + 1`
done

i=0
j=1
while [ $i -lt $size ] 
do	
	j=1
	while [ $j -lt $size ]
	do
		
		if [ ${arr[`expr $j - 1`]} -gt ${arr[j]} ] 
		then
			temp=${arr[`expr $j - 1`]}
			arr[`expr $j - 1`]=${arr[j]}
			arr[j]=$temp
		fi
		j=`expr $j + 1`
	done
	i=`expr $i + 1`
done

echo -n "Sorted Array: "
i=0
while [ $i -lt $size ]
do
	echo -n "${arr[i]} "
	i=`expr $i + 1`
done

