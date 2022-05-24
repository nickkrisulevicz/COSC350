//Nick Krisulevicz
//COSC 350
//Project 2
//05/06/2022
//program to compress a file by using Huffman Coding
//huff.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "sharedlib.h"

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
	
	//initialize the struct with 256 indexes, one for each ascii value
	struct pair freqtable[256];

    	//create a for loop that initializes each index to the value of the character it will store
	for(int index = 0; index < 256; index++){
		//initialize each integer from 0 to 128 its corresponding ASCII value in the table
		freqtable[index].value = index;
		//initialize the frequency of each value to zero
		freqtable[index].freq = 0;
	}


	//initialize a cursor for lseek
	int cursor = 0;
 	//lseek to the end of the file to check the file size
	off_t fileend = lseek(fd, 0, SEEK_END);
  	//lseek back to the beginning of the file to begin reading
	lseek(fd, 0, SEEK_SET);

	//print the size of the file to make sure the file was opened and can be read properly
	printf("Size of file is: %d bytes", (int)fileend);
	printf("\n");

    	//until the end of the file, read every character and its frequency
	while (read(fd, buf, 1) > 0){
		int readindex = (int)buf[0];
		if(*buf > 0){
			freqtable[readindex].value = *buf;
        		freqtable[readindex].freq++;
		}
	}
	printf("pair values and frequencies done\n");

	//declare the priority queue
	struct qnode *priorityqueue;

	for(int index = 0; index < 256; index++){
		//create a temporary tnode struct to assign the new node to
		struct tnode *pushnode = createtreenode(freqtable[index]);
		//push the new node into the queue with the push function
		pushqueue(&priorityqueue, &pushnode);

	}
	printf("push queue done\n");

	printpriority(&priorityqueue);
	//printqueue(&priorityqueue);
	printf("print queue done\n");

	//build a tree out of the nodes
	//pass the nodes into the tree one by one from the queue

	//encode the node values into pack

	//write the pack to the external file



	return 0;
}
