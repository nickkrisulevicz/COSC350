//Nick Krisulevicz
//COSC 350
//Lab 8
//04/28/2022
//task3.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void handler(int sig){
	if(sig == SIGUSR1){
		printf("Hi honey! Anything wrong?\n");
	}
	else if(sig == SIGUSR2){
		printf("Do you make trouble again?\n");
	}
}

int main(){
	pid_t child1;
	pid_t child2;
	child1 = fork();
	if(child1 == 0){
		kill(getppid(), SIGUSR1);
	}
	else{
		wait(NULL);
		signal(SIGUSR1, handler);	
	}
	
	child2 = fork();
	if(child2 == 0){
		kill(getppid(), SIGUSR2);
	}
	else{
		wait(NULL);
		signal(SIGUSR2, handler);
	}
	exit(0);

}
