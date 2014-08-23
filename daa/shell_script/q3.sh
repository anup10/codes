#!/bin/bash

check()
{
diff $1 $2
if [ $? -eq 0 ]
then
	echo "same"
else
	echo "different"
fi
}

echo "read two files"
read f1
read f2
check $f1 $f2		
