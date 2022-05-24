//Nick Krisulevicz
//COSC 350
//Lab exercise 
//05/12/2022
//q1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int glob = 0;

void *calc(void *tid){
	for(int i = 0; i < 10000; i++){
		glob++;
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[5];
	for(int i = 0; i < 5; i++){
		pthread_create(&threads[i], NULL, calc, &glob);
	}
	printf("Global variable value: %d\n", glob);
	exit(0);
}
