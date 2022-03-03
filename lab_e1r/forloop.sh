#Nick Krisulevicz
#COSC 350 _ Lab E1R
#03/03/2022
#forloop.sh

#! /bin/sh

echo -e "For loop with break \n"

for myloop in 1 2 3 4 5; do
	echo "$myloop"
	if [ "$myloop" -eq 3 ]
	then
		break
	fi
done

echo -e "\nFor loop with continue \n"

for myloop in 1 2 3 4 5; do
	echo "$myloop"
	if [ "$myloop" -eq 3 ]
	then
		continue
	fi
done

exit 0;
