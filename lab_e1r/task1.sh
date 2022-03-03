#Nick Krisulevicz
#COSC 350 Exam 1 review lab
#task1.sh
#03/03/2022

#! /bin/sh
n=$1
m=$2
sum=0
for ((i=$n; i<=$m; i++));
do
	sum=$(expr $sum + $i)
done
echo The sum is $sum
exit 0;
