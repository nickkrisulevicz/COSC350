//Nick Krisulevicz
//COSC 350
//Lab 8
//05/12/2022
//task2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>


//global variable for the scores array
#define arrsize 10
int scores[arrsize];

//function for the first thread to get the scores
void *getscores(void *tid){
        int temp;
        //for loop to initialize each element of the scores array with a number from 0-20
        for(int i = 0; i < arrsize; i++){
                temp = rand() % 20;
                scores[i] = temp;
                printf("%d ", scores[i]);
        }
        printf("\n");
        //exit the thread
        pthread_exit(NULL);
}

//function to average the scores for the second thread
void *avgscores(void *tid){
        int total = 0;
        //add all of the scores together
        for(int i = 0; i < arrsize; i++){
                total += scores[i];
        }
        //divide the total and get the average
        total /= 10;
        printf("Average is: %d\n", total);
        //exit the thread
        pthread_exit(NULL);
}

//function to get the min and the max for the third thread
void *minmax(void *tid){
        //initialize the min and max
        int min = 0;
        int max = 0;
        //for each element, find the min and the max
        for(int i = 0; i < arrsize; i++){
                //if current is less than min, make current the new min 
                if(min > scores[i]){
                        min = scores[i];
                }
                //if max is more than current, make current the new max
                if(max < scores[i]){
                        max = scores[i];
                }
        }
        printf("Min is %d, max is %d\n", min, max);
        //exit the thread
        pthread_exit(NULL);
}

//function to clear the buffer for the fourth thread
void *clearbuf(void *tid){
        //for every element in the scores array, assign it to zero to clear the buffer
        for(int i = 0; i < arrsize; i++){
                scores[i] = 0;
        }
        //print that the buffer has been reset
        printf("Reset buffer\n");
        for(int i = 0; i < arrsize; i++){
                scores[i];
        }
        //exit thread
        pthread_exit(NULL);
}

//main function
int main(){
        //create an array of four threads
        pthread_t threads[4];
        //create the first thread
        pthread_create(&threads[0], NULL, getscores, &scores);
        wait(NULL);
        //create the second thread
        pthread_create(&threads[1], NULL, avgscores, &scores);
        wait(NULL);
        //create the thrid thread
        pthread_create(&threads[2], NULL, minmax, &scores);
        wait(NULL);
        //create the fourth thread
        pthread_create(&threads[3], NULL, clearbuf, &scores);
        wait(NULL);
 
        exit(0);
}