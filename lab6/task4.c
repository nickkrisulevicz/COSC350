//Nick Krisulevicz
//COSC 350
//Lab 6
//04/21/2022
//task4.c

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
        
        pid_t pid;
        char *message;
        int n;
        int exit_code;
        printf("fork program starting\n");
        pid = fork();
        switch(pid){
        case -1:
                perror("fork failed");
                exit(1);
        case 0:
                if(execv("child", argv) <0){
                        printf("Exec failed!\n");
                        exit(1);
                }
                message = "This is the child";
                n = Nc;
                exit_code = 37;
                break;
        default:
                message = "This is the parent";
                n = Np;
                exit_code = 0;
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
        if (pid != 0) {
                int stat_val;
                pid_t child_pid;
                child_pid = wait(&stat_val);
                printf("Child has finished: PID = %d\n", child_pid);
                if(WIFEXITED(stat_val))
                        printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
                else
                printf("Child terminated abnormally\n");
        }
        exit(exit_code);
}