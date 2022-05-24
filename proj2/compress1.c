//Nick Krisulevicz
//COSC 350
//Project 2
//05/06/2022
//Compress a file from command line using huffman coding
//compress.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "sharedlibrary.h"

int main(int argc, char *argv[]){
	//error checking, user needs to enter one argument, the name of the file to be compressed
	if(argc == 2){
		printf("File input: %s\n", argv[1]);
	}
	else if(argc < 2){
		printf("Please enter at least one argument!\n");
		exit(1);
	}
	else if(argc > 2){
		printf("Please only enter one argument!\n");
		exit(1);
	}

        //open the input file
        int fd = open(argv[1], O_RDONLY);

	//error check the input file
	if(fd == -1){
		printf("File does not exist!\n");
		exit(1);
	}

	//test printf to see if the file is being read
	printf("File descriptor is %d\n", fd);

	//Initialize the character buffer for when the file is read from
	char buf[1];

}