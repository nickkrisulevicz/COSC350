//Nick Krisulevicz
//COSC 350
//Project 2
//Use Huffman Coding to create a program to compress a file
//compress.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "shlib.h"

//from shlib.h,
//initialize a pair struct
//use functions for priority queue

//main function, in order to work, user needs to pass in one argument from command line, the file name to be compressed
int main(int argc, char *argv[]){

	//If user inputs correct file name, proceed with the program. Otherwise, terminate the program with an error message
	if(argc == 2){
		printf("File input: %s\n", argv[1]);
	}

	//if the user inputs no arguments, print an error message
	else if(argc < 1){
		printf("You need to input a file to compress!\n");
		exit(1);
	}

	//if the user inputs more than one argument, print an error message
	else if(argc < 2){
		printf("Too many arguments!\n");
		exit(1);
	}

	//Open the file the user input
	int fd = open(argv[1], O_RDONLY);

	//if the file the user input is not in the directory, print an error message
	if(fd == -1){
		printf("File does not exist!\n");
		exit(1);
	}

	//test printf to see if the file is being read
	printf("File descriptor is %d\n", fd);

	//Initialize the character buffer for when the file is read from
	char buf[1];
	
	//initialize the struct with 128 indexes, one for each ascii value
	struct pair freqtable[128];

	//create a for loop that initializes each index to the value of the character it will store
	for(int index = 0; index < 128; index++){
		//initialize each integer from 0 to 128 its corresponding ASCII value in the table
		freqtable[index].value = index;
		//initialize the frequency of each value to zero
		freqtable[index].freq = 0;
	}


	//initialize a cursor for lseek
	int cursor = 0;
	off_t fileend = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	//print the size of the file to make sure the file was opened and can be read properly
	printf("Size of file is: %d bytes", (int)fileend);
	printf("\n");

	//until the end of the file, read every character and its frequency
	while (read(fd, buf, 1) > 0){
		int readindex = (int)buf[0];
		freqtable[readindex].freq++;
	}

	//print out all ASCII characters and their frequency in the file
	//EDIT: this block of code is no longer necessary since there is a function to print the queue
	/*
	for(int i = 0; i < 128; i++){
		printf("Value: %c Frequency: %d\n", freqtable[i].value, freqtable[i].freq);
	}
	*/


	//At this point, build the priority queue with the array of values and freqnuencies


	//initialize a qnode struct which will act as the front of our queue
	//printf("initialized queue\n");
	struct qnode *priorityqueue;

	//create a for loop and call the createnode function to create a node out of the corresponding pair
	//then call pushqueue function to add the node into the queue and repeat until loop is done
	printf("Pushing queue\n");
	for(int i = 0; i < 128; i++){
		struct qnode *newnode = createnode(freqtable[i]);
		pushqueue(&priorityqueue, newnode);
	}

	printf("push successful\n");

	//print function currently causes segmentation fault and so it is not used
	//printqueue(&priorityqueue);

	//create another for loop and pop each elemement from the queue
	//since printqueue function is busted, the printing is achieved by calling a top function and then popping it from the queue
	//printf("popping queue\n");
	for(int i = 0; i < 128; i++){
		printf("Value: %c Frequency: %d\n", topnode(&priorityqueue->nodevalue.value), topnode(&priorityqueue->nodevalue.freq));
		popqueue(&priorityqueue);
	}

	//printf("queue has been popped\n");



	//At this point, build the Huffman Tree

	//pseudocode for tree building
	/*
	 * while(queue is not empty){
	 * 	tnode *t1 = pop(...)
	 * 	if(queue is empty){
	 * 		get out of while loop
	 * 	}
	 * 	tnode *t1 = pop(...)
	 * 	struct pair p
	 * 	p.value = t1->nodevalue.value
	 * 	p.freq = t1->nodevalue.freq
	 *	tnode *p1 = createtreenode(p)
	 *	p1->left = t1
	 *	p2->right = t2
	 *	t1->parent = t1
	 *	t2->parent = p1
	 *	push(..., p1)
	 *
	 *
	 *
	 */

	//At this point, delete the normal contents of the file and write the compressed tree to the file
	


	//Close the file
	close(fd);
	
	return 0;
}

