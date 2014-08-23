#!/bin/sh

print ()
{

y=`expr $3 - $2`

head -$3 $1 | tail -$y
} 









#echo "Enter file name and line numbers:"
read f1
read num1
read num2
print $f1 $num1 $num2
