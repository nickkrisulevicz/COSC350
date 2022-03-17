#Nick Krisulevicz
#COSC 350 - Lab 4
#Midterm Question 9
#03/17/2022
#midterm9.sh

#! /bin/sh

#fibonacci sequence:
#use a loop, keep the previous value, n-1, n-2
#n3=n1+n2
#n1=n2
#n3=n2

iter=0
n1=0
n2=1
n3=0

until [ $iter -eq $1 ]; do
	echo $n3
	let n3=$n1+$n2
	let n1=$n2
	let n2=$n3
	let iter++
done
exit 0;
