//Nick Krisulevicz
//COSC 350
//Lab 5
//03/24/2022
//task1.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <utmp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
	//If the user does not provide file name and a path to move it to, print a warning message
	if(argc != 3)
		printf("Two arguments required!\n");

	int fd = open(argv[1], O_RDONLY | O_WRONLY);
		
	//Take the string of the path this program is in and concatenate it with the file name the user input
	char string1[] = "/home/nickkrisulevicz/COSC350/lab5/";
	strcat(string1, argv[1]);

	//Concatenate the new file path
	char string2[100];
	strcpy(string2, "./");
	strcat(string2, argv[2]);
	strcat(string2, "/");
	strcat(string2, argv[1]);

	//Link the existing path to the new path
	link(string1, string2);

	//Unlink th existing link
	unlink(string1);

	//Close the file
	close(fd);

	return 0;
}
