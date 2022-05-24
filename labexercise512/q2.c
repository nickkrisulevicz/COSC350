//Nick Krisulevicz
//COSC 350
//Lab exercise 
//05/12/2022
//q2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
int glob = 0;

void *calc(void *tid){
	pthread_mutex_lock(&mut);
	for(int i = 0; i < 10000; i++){
		glob++;
	}
	pthread_mutex_unlock(&mut);
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[5];
	for(int i = 0; i < 5; i++){
		pthread_create(&threads[i], NULL, calc, &glob);
	}
	for(int i = 0; i < 5; i++){
		pthread_join(threads[i], NULL);
	}
	printf("Global variable value: %d\n", glob);
	exit(0);
}
