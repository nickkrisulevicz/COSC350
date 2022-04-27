//Nick Krisulevicz
//COSDC 350
//Lab 6
//4/21/2022
//child.c

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

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

        char *message = "This is the child";
        for(; Nc > 0; Nc--) {
		printf("%s\n", message);
		sleep(Tc);
        }


        exit(37);
}