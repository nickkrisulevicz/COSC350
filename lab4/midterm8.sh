#Nick Krisulevicz
#COSC 350 - Lab 4
#03/17/2022
#Midterm Question 8
#midterm8.sh

#! /bin/sh

c=0
cplus=0
header=0
shell=0
other=0

for file in *
do
	case $file in
		*.c) let c++ ;;
		*.cpp) let cplus++ ;;
		*.h) let header++ ;;
		*.sh) let shell++ ;;
		*) let other++ ;;
	esac
done

echo -e "In this directory, there are:"
echo -e "$c .c files"
echo -e "$cplus .cpp files"
echo -e "$header .h files"
echo -e "$shell.sh files"
echo -e "$other all other types of files"

exit 0;
