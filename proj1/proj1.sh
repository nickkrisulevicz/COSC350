#Nick Krisulevicz
#COSC 350
#Project 1
#Employee Database Program to Manipulate Employee Data and Write Data to External File
#03/10/2022
#proj1.sh

#! /bin/sh


line1="\t Employee Information		"
line2="-----------------------------------------"
line3="First \t Last \t	SSN \tDOB \t Salary	"
line4="Name \t Name				"
line5="-----------------------------------------"

listheader(){
	echo -e $line1
	echo -e $line2
	echo -e $line3
	echo -e $line4
	echo -e $line5
}

runner=1;
while [ $runner -ne 0 ]; do
	listheader
	let runner=0
done

exit 0;
