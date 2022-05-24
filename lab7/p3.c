//Nick Krisulevicz
//COSC 350
//Lab 7 - Exam 2 problem 3
//04/14/2022
//p3.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]){
	int fd1 = open("input", O_RDONLY); //open file to read
	int fd2 = open("output", O_RDWR | O_CREAT, 0777); //open file to wrote
	
	char buffer; //create the buffer
	off_t filebegin = lseek(fd2, 0, SEEK_SET); //get the file begin which should just be zero
	off_t fileend = lseek(fd1, 0, SEEK_END); //get the file end which will be the size of the file

	int revcounter = fileend; //create a counter that starts from the size of the file
	printf("revcounter: %d\n", revcounter);
	int begcounter = filebegin; //create a counter that starts from zero
	printf("begcounter: %d\n", begcounter);

	lseek(fd1, 0, SEEK_END); //set the offsets for the two files
	lseek(fd2, 0, SEEK_SET);
	
	while(revcounter != 0){ //iterate through the loop until the reverse counter reaches zero
		read(fd1, &buffer, 1); //read from the input file one character into the buffer
		write(fd2, &buffer, 1); //write one character from the buffer into the output file
		revcounter--; //decrement the reverse counter
		begcounter++; //increment the forward counter
		lseek(fd1, revcounter, SEEK_SET); //reset the offsets
		lseek(fd2, begcounter, SEEK_SET);
	}
	
	close(fd1); //close the files
	close(fd2);
	return 0;
}
