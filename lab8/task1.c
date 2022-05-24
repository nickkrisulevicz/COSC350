//Nick Krisulevuicz
//COSC 350
//Lab 8
//04/28/2022
//task1.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

//signal handler
void sighandler(int sig){
	//if SIGINT is received from ctrl + c, then print a message and exit the program
	if(sig == SIGINT){
		printf("Received SIGINT (ctrl + c). Exiting program\n");
		exit(0);
	}
}

int main(){
	//print message telling user program will end once they press ctrl + c
	printf("Awaiting ctrl + c signal\n");
	sleep(1);
	//if program receives the signal, call the sig handler, otherwise print an error message
	if(signal(SIGINT, sighandler) == SIG_ERR){
		printf("Can't catch SIGINT!\n");
	}
	//infinitely pause until the user causes the signal to be sent
	while(1){
		pause();
	}
}
