#Nick Krisulevicz
#COSC 350 - LabE1R
#03/03/2022
#task8.sh

#! /bin/sh

echo "Positional parameters before set \`uname -a\` :"
echo "Command-line argument #1 = $1"
echo "Command-line argument #2 = $2"
echo "Command-line argument #3 = $3"
set `uname -a`

echo $_
echo "Positional parameters after set \`uname -a\` :"
i=1
for ARG in " $@ "; do
	echo "Field " $i " of 'uname -a' = $ARG"
	let i++
done
exit 0;
