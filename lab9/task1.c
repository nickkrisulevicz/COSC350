//Nick Krisulevicz
//COSC 350
//Lab 8
//05/12/2022
//task1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

//global variables to store the input from the user and provide it to threads
int n = 0;
int m = 0;

//factorial function for factorial thread
void *factorial(void *tid){
        int total = 1;
        //for loop to calculate product of factorial
        for(int i = 1; i < n; i++){
                total *= i;
        }
        //print output to console
        printf("Factorial of %d is: %d\n", n, total);
        //exit the thread
        pthread_exit(NULL);
}

//summation function for sum thread
void *summation(void *tid){
        int total = 0;
        //for loop to calculate sum
        for(int i = 0; i < n; i++){
                total += i;
        }
        //print output to console
        printf("Summation of %d is: %d\n", n, total);
        //exit the thread
        pthread_exit(NULL);
}

int main(int argc, char *argv[]){
        //error checking
        if(argc != 2){
                printf("Invalid number of arguments! Enter one integer!\n");
                exit (0);
        }

        //convert the command line argument into an integer and store it in the global variables
        char *a = argv[1];
        n = atoi(a);
        m = n;
        printf("The number you entered is %d\n", n);

        //create an array of two tids
        pthread_t tid[2];
        //create the factorial thread
        pthread_create(&tid[0], NULL, factorial, &n);
        //main function needs to wait to finish until the threads finish
        wait(NULL);
        //create the summation thread
        pthread_create(&tid[1], NULL, summation, &m);
        //wait until this thread is done as well
        wait(NULL);

        exit(0);
}