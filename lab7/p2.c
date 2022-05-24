//Nick Krisulevicz
//COSC 350
//Lab 7 - Exam 2 problem 2
//04/14/2022
//p2.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	//error check in case user inputs wrong amount of arguments
	if(argc != 2){
		printf("Provide only one argument!\n");
		exit(1);
	}
	
	//open the file the user inputs
	int fd = open(argv[1], O_RDONLY);

	//create a variable with the same return type as the lseek system call
	off_t fs;

	//assign this variable the amount of bytes lseek returns from the end of the file
	fs = lseek(fd, 0, SEEK_END);

	//print the amount of bytes the file is
	printf("File size is: %d bytes!\n", fs);

	//close the file
	close(fd);
	return 0;
}
