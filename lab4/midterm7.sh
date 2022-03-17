#Nick Krisulevicz
#COSC 350 - Lab 4
#Part 1 - Question 7 from Midterm
#03/17/2022
#midterm7.sh

#! /bin/sh

total=0;
for i in $@
do
	let total=$total+$1
	shift
done
echo "The sum of all command line integers is: " $total
exit 0;
