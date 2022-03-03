#Nick Krisulevicz
#COSC 350 - Lab E1R
#03/03/2022
#task6.sh

#! /bin/sh

echo -e "String input is: $1 \n"

l=`expr length $1`
echo -e "Length of the string is $l \n"

s=`expr substr $1 2 4`
echo -e "Substring of the string from index 2-4 is: $s \n"

exit 0;
