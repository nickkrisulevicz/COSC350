//Nick Krisulevicz
//COSC 350
//Lab 8
//05/12/2022
//task3.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
        //error checking for correct amount of arguments
        if(argc != 3){
                printf("Invalid input! Enter two integers!\n");
                exit(0);
        }

        //initialize a pid
        pid_t pid;
        //call fork to create child process
        pid = fork();
        //if pid is the child process, add the arguments
        if(pid == 0){
                //convert the two command line arguments to integers
                int n = atoi(argv[1]);
                int m = atoi(argv[2]);
                //add the two arguments
                int total = n + m;
                //print the total
                printf("Sum is %d\n", total);
        }
        //if the pid is the parent process, run until the child is done
        else if(pid > 0){
                wait(NULL);
        }
}