//Nick Krisulevicz
//COSC 350
//Lab 7 - Exam 2 problem 6
//04/14/2022
//p6.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>


//The code for problem 6 was given to us on the exam
//The problem was to figure out the output from the parent and child processes both running in the console

int main(int argc, char *argv[]){
	int var;
	pid_t pid;

	var = 888;
	printf("Before fork\n");

	pid = fork();

	if(pid == 0)
		var++;
	else if(pid > 0)
		var--;
	else
		printf("Fork failed\n");

	printf("pid=%d, var=%d\n", getpid(), var);

	return 0;
}
