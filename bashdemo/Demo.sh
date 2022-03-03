#Nick Krisulevicz
#COSC 350
#demo for a bash shell script
#Demo.sh
#02/18/2022
#Do it for Dale

#!/bin/sh

colour(){
	case $1 in
		Black_white)
			echo -e "3[40;37m"
			;;
		Black_green)
			echo -e "3[40;32m"
			;;
		Black_cyan)
			echo -e "3[40;36m"
			;;
		Red_yellow)
			echo -e "3[41;33m"
			;;
		Yellow_blue)
			echo -e "3[43;34m"
			;;
	esac
}

search(){
	colour black_white
	clear
	echo -e "Please enter name >>>\c"
	read NAME
	if [ ! -f ./record ]; then
		echo "You must have some scores before you can search!"
		sleep 2
		clear
		return
	fi
	if [ -z "$NAME" ]; then
		echo "You didn't enter a name!"
		echo -e "Please enter a name >>>\c"
	fi
	echo "The information you query is: $NAME"
	grep "$NAME" ./record 2> /dev/null
	case "$?" in
		1) echo "Name not in record"
			;;
		2) echo "You did not enter a name to search"
			sleep 2
			search
			;;
	esac
}

add(){
	clear
	echo "Enter a name and score of a record"
	echo -e "\c"
	if [ ! -f ./record ]; then
		touch record
	fi
	read NEWNAME
	echo "$NEWNAME" >> ./record
	sort -o ./record ./record
	echo "Added success"
	sleep 2
}

delete(){
	clear
	echo -e "Please enter name>>> "
	read NAME
	if [ ! -f ./record ]; then
		echo "Record is empty, please add it first"
	else
		cp record record.bak
		grep "$NAME" ./record.bak > /dev/null
		if [ $? != 0 ]; then
			echo "This man does not exist"
		else
			grep -v "$NAME" ./record.bak > record
			echo "Delete successfully"
		fi
	rm -f record.bak
	fi
	sleep 1
}

display(){
	colour Black_white
	more ./record
}

edit(){
	vim ./record
}

help(){
	clear
	colour Black_cyan
	echo "This is a student's record program by!"
}

quit(){
	clear
	colour Black_white
	exit
}

clear
while :
do
	colour Red_yellow
