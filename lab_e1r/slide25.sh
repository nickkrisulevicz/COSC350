#Nick Krisulevicz
#COSC 350 - Lab E1R
#03/03/2022
#task6.sh
#!/bin/sh
a=987abCD1234RTab
echo "The string being operated upon is \"$a\"."
b=`expr length $a`
echo "Length of \"$a\" is $b."
b=`expr index $a 2`
echo "Numerical position of first \"2\" in \"$a\" is \"$b\"."
b=`expr substr $a 2 6`
echo "Substring of \"$a\", starting at position 2,\ and 6 chars long is \"$b\"."
b=`expr match "$a" '[0-9]*'`
echo Number of digits at the beginning of \"$a\" is $b.
b=`expr match "$a" '\([0-9]*\)'`.
echo "The digits at the beginning of \"$a\" are \"$b\"."
exit 0
