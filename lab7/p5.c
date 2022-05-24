//Nick Krisulevicz
//COSC 350
//Lab 7 - Exam 2 problem 5
//04/14/2022
//p5.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int numb = 0;
	int notnumb = 0;
	for(int i = 0; i < argc; i++){
		char temp = *argv[i];
		int temp1 = atoi(temp);
		if(temp1 % 128 >= 48 && temp1 % 128 <= 57){
			numb++;
		}
		else{
			notnumb++;
		}

	}
	printf("Command line arguments that are a number: %d\n", numb);
	printf("Non number command line arguments: %d\n", notnumb);
	return 0;
}
