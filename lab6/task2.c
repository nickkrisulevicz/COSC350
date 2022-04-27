//Nick Krisulevicz
//COSC 350
//Lab 6
//04/21/2022
//task2.c

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if(argc != 5){
		printf("Invalid number of arguments!\n");
		exit(0);
	}

	int Nc = atoi(argv[1]);
	int Np = atoi(argv[2]);
	int Tc = atoi(argv[3]);
	int Tp = atoi(argv[4]);

	printf("%d\n", Nc);
	printf("%d\n", Np);
	printf("%d\n", Tc);
	printf("%d\n", Tp);

	pid_t pid;
	char *message;
	int n;
	printf("fork program starting\n");
	pid = fork();
	switch(pid){
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = Nc;
			break;
		default:
			message = "This is the parent";
			n = Np;
			break;
	}
	for(; n > 0; n--) {
		if(pid == 0){
			puts(message);
			sleep(Tc);
		}
		else{
			puts(message);
			sleep(Tp);
		}
	}
exit(0);
}