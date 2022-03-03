#Nick Krisulevicz
#COSC 350 - Lab E1R
#03/03/2022
#task7.sh

#! /bin/sh

printf "%d\n" 5 #print decimal 5 followed by new line

printf "%f\n" 5 #print float followed by new line defaults to 6 spaces

printf "Hello, $USER.\n\n" #print text followed by variable user

distance=15
printf "Distance is %5d miles\n" $distance #print text and variables with 5 spaces

printf "Two separate \n lines \n" #print two separate lines with escape seuences

printf "There are %d values at %d euros. \n" 64 1500 #print a string with variables mixed in

printf "%d\n " 0xF #convert a hex to decimal

printf "%0x%X\n " 15 #convert decimal number to hexadecimal

printf "0%o\n " 8 #convert decimal to octal

printf "%d\n " 010 #convert octal to decimal

exit 0;
