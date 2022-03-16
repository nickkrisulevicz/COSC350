#Nick Krisulevicz
#COSC 350
#Project 1
#Employee Database Program to Manipulate Employee Data and Write Data to External File
#03/10/2022
#proj1.sh

#! /bin/sh

#add a color scheme to the program
echo -e "\e[36;47m"

#list header function to print the top of the list
#this contains teh details of the columns tat make up the contents of the record file
#each entry is separated indivudually by line
listheader(){
	#formatted lines stored in variables
	line1="\t Employee Information		"
	line2="-----------------------------------------"
	line3="First \t Last \t	SSN \tDOB \t Salary	"
	line4="Name \t Name				"
	line5="-----------------------------------------"

	#print the variables in the console
	echo -e $line1
	echo -e $line2
	echo -e $line3
	echo -e $line4
	echo -e $line5
}

#insert function to a new person into the database
insert(){
	#check if the record exists before adding to it
	echo -e "\c"
	if [ ! -f ./record ]; then
		#create the record file if it does not exist
		touch record 
	fi

	#prompt user to input first name and store in variable
	echo -e "Enter their first name:"
	read firstname
	
	#prompt user to input last name and store in variable
	echo -e "Enter their last name:"
	read lastname

	#prompt user to input social security number and store in variable
	echo -e "Enter their SSN:"
	read ssn
	
	#before moving on, check if ssn is already in use in the record
	#make a backup of record for temporary use
	cp record record.bak
	#output the line with the pre-existing ssn and send it to the garbage
	grep "$ssn" ./record > /dev/null
	#if that grep found a matching ssn, cancel the insertion
	if [ $? == 0 ]; then
		echo -e "This person already exists!\n"
		sleep 3
		return
	fi

	#prompt user to input date of birth and store it in a variable
	echo -e "Enter their DOB:"
	read dob
	
	#prompt user to input salary and store in in a variable
	echo -e "Enter their salary:"
	read salary

	#send the user input data as one concantenated string to the record file
	echo -e "$firstname \t $lastname \t $ssn \t $dob \t \$$salary" >> ./record
	#sort the entries in the record to make it look nicer
	sort -o ./record ./record
	echo -e "Success adding person to database!\n"
	#remove the backup of record since it was temporary
	rm record.bak
	sleep 3
}

#modify function to edit a pre-existing person in the record
modify(){
	#prompt user to input ssn to search for in teh record
	echo -e "Enter an SSN of a person to modify:"
	read ssnsearch
	
	#if the record does not exist, warn user of this
	if [ ! -f ./record ]; then
		echo -e "There are no records to search for!\n"
		sleep 3
		clear
		return
	fi
	
	#if the user hits enter without entering an ssn, warn user of this
	if [ -z "$ssnsearch" ]; then
		echo -e "You did not enter an SSN to search for!\n"
		sleep 3
		clear
		return
	fi

	#make temporary backup of record to use for the modify operation
	cp record record.bak
	#search for a match of the target ssn and send the output to the garbage
	grep "$ssnsearch" ./record.bak > /dev/null
	#if the grep operation did not find a match, tell the user this
	if [ $? != 0 ]; then
		echo -e "This person does not exist!\n"
		sleep 3
		clear
		return
	else
		#if it did find a match, overwrite the record with the backup record with target ssn gone
		#prompt the user to confirm their update request
		echo -e "Are you sure you want to update this person? (Y/N)"
		read updateconfirmation
		#case statement to handle user responses for update
		case $updateconfirmation in
			Y)	#if user inputs y, go through with update procedure
				grep -v "$ssnsearch" ./record.bak > record
				;;
			y)	#if user inputs Y, also do update process
				grep -v "$ssnsearch" ./record.bak > record
				;;
			N)	#if user enters N, decline update and return to menu
				echo -e "Update cancelled\n"
				sleep 3
				return
				;;
			n)	#if user enters n, also cancel the update
				echo -e "Update cancelled\n"
				sleep 3
				return
				;;
			*)	#if user enters invalid input, return to menu
				echo -e "Invalid input! Enter y or n\n"
				sleep 3
				return
				;;
		esac
	fi
	
	#the previous entry is deleted, now the user inputs updated information which is stored
	#in the same social security number and put back in the record

	#prompt user to enter an updated first name
	echo -e "Enter updated first name:"
	read firstname

	#prompt user for an updated last name
	echo -e "Enter updated last name:"
	read lastname

	#prompt user for an updated date of birth
	echo -e "Enter updated date of birth:"
	read dob

	#prompt user for an updated salary
	echo -e "Enter updated salary:"
	read salary

	#note: there was no updated social security number since that does not change with the modify function

	#commit the updated string into the record
	echo -e "$firstname \t $lastname \t $ssnsearch \t $dob \t \$$salary" >> ./record
	sort -o ./record ./record
	#get rid of the backup record since it was temporary
	rm record.bak
	
	echo -e "Success modifying person!\n"
	sleep 3
}

#delete function to remove an entry from the database record
delete(){
	#prompt user to input a target ssn to search for and delete
	echo -e "Enter an SSN to delete:\n"
	read ssnsearch

	#if the record does not exist, then warn the user that there is nothing to delete
	if [ ! -f ./record ]; then
		echo -e "There are no records to search for!\n"
		sleep 3
		clear
		return
	fi

	#if the user presses enter without inputting an ssn, warn the user of this error
	if [ -z "$ssnsearch" ]; then
	        echo -e "You did not enter an SSN to search for!\n"
		sleep 3
		clear
		return
	fi

	#make a temporary backup copy of record
	cp record record.bak
	#search for the target ssn in the record backup and send the output to the garbage
	grep "$ssnsearch" ./record.bak > /dev/null
	#if the target ssn is not found, inform the user it does not exist
	if [ $? != 0 ]; then
		echo -e "This person does not exist!\n"
		sleep 3
		clear
		return
	#if output occurs, prompt the user for comfirmation before deleting that person
	else
		#take user input for confirmation and store it in a variable
		echo -e "Are you sure you want to delete this person? (Y/N)"
		read delconfirmation
		#use the variable for a case statement that decides whether or not to confirm deletion
		case $delconfirmation in
			y)	#if y is entered, delete the entry by overwriting the record with the backup record missing the target entry
				grep -v "$ssnsearch" ./record.bak > record
				echo -e "Deleted successfully!\n"
				sleep 3
				;;
			Y)	#if Y is entered, do the same procedure in the event of Y
				grep -v "$ssnsearch" ./record.bak > record
				echo -e "Deleted successfully!\n"
				sleep 3
				;;
			n)	#if n is entered, cancel the deletion of the record and go back to the main menu
				echo -e "Deletion cancelled\n"
				sleep 3
				;;
			N)	#if N is entered, do the same thing as if n is entered
				echo -e "Deletion cancelled\n"
				sleep 3
				;;
			*)	#everything else is invalid input
				echo -e "Invalid input! Enter y or n\n"
				sleep 3
				;;
		esac
	fi
	#get rid of the temporary backup file of the record
	rm record.bak
}

#retrieve function is the search function for the user and outputs one entry with the target ssn to the console
retrieve(){
	#prompt user for input for a target ssn to search for
	echo "Enter an SSN to search for"
	read ssnsearch

	#if the record does not exist, inform user there are no records to retrieve
	if [ ! -f ./record ]; then
		echo -e "There are no records to search for!\n"
		sleep 3
		clear
		return
	fi
	
	#if the user errantly inputs nothing, tell the user if this mistake
	if [ -z "$ssnsearch" ]; then
		echo -e "You did not enter an SSN to search for!\n"
		sleep 3
		clear
		return
	fi
	
	#perform a search of the record file and return a line that contains the target social security number
	#if the target ssn exists, this statement displays it in the console
	grep -w "$ssnsearch" record	

	#case statement to resolve conditions where either the target ssn is not in the file or if the user entered nothing
	case "$?" in
		1)	#this case is where the target ssn is not found
			echo -e "There is no record of this person\n"
			sleep 3
			;;
		2)	#this case is where the user entered errant input
			echo -e "Invalid input, please enter an SSN to search\n"
			sleep 3
			#the retrieve function is called again so the user can have another chance to input a target ssn
			retrieve
			;;
	esac
	echo -e "\n"
	
}

#the printdatabase function prints the entire database for the user to read
printdatabase(){
	#the listheader function is called to display the details of the record at the top of the screen
	listheader
	#the cat command displays all the contents of the record, and shows all entries with their names, ssn, dob and salary
	cat ./record
	echo -e "\n"
}

#the displaymenu function takes a series of strings and prints them on the screen for the user to interact with.
#the user inputs their preferred action in the main function because of this prompt
displaymenu(){
	echo -e "Make a selection on a database action below:\n"
	echo -e "1. Insert a new person into the database"
	echo -e "2. Search the database for person by SSN"
	echo -e "3. Modify data for a person in the database"
	echo -e "4. Delete a person from the database"
	echo -e "5. Print the whole database"
	echo -e "6. Quit the database"
	echo -e "----------------------------------------\n"
}


#---------------------------------------------------------------------------------------------------

#this is the main function


#the runner variable is intended to allow the main program to repeatedly run until the value changes
#once this happens, the program terminates
runner=n;
#while loop to continually run the program until the end condition is met
while [ "$runner" != "y" ]; do
	#call displaymenu function
	displaymenu
	#take user input for a correspondinf integer for the database action they want to choose
	read userchoice
	#case statement that performs a function according to what integer they input
	case $userchoice in
		1) 	#inputting 1 calls the insert function for the user to create a new entry
			insert
			#the screen is cleared to make the program look less cluttered and the loop continues
			clear
			;;
		2) 	#inputting 2 calls the retrieve function for the user to search for a specific entry and display it in the console
			retrieve
			#the screen is not cleared in this case so the user can see what they searched for
			;;
		3) 	#inputting 3 calls the modify function for the user to modify an existing entry
			modify
			#clear the screen to remove clutter
			clear
			;;
		4) 	#inputting 4 calls the delete function so the user can remove an entry from the database
			delete
			#clear the screen and remove clutter
			clear
			;;
		5) 	#inputting 5 calls the printdatabase function and prints the list header and the contents of the record in the console
			printdatabase
			#the screen is not cleared in this case so the user can take time to read the records
			;;
		6) 	#inputting 6 assigns a different value to the runner variable so the end condition is met for the while loop
			#the program terminates after a message is displayed
			echo "Goodbye!"
			sleep 1
			#reset the color scheme of the console back to black and white
			echo -e "\e[40;37m"
			#assigning of the runner value to meet the end condition
			runner=y
			;;
		*) 	#inputting anything other than 1 2 3 4 5 6 will result in invalid input message, and the user will be prompted again
			echo "Invalid input! Please choose a valid action"
			sleep 2
			clear
			;;
	esac
done

exit 0;
