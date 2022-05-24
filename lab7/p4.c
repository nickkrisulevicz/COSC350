//Nick Krisulevicz
//COSC 350
//Lab 7 - Exam 2 problem 4
//04/14/2022
//p4.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	printf("Please enter a number for the length of the string:\n");
	int leng;
        leng = scanf("%d", &leng);
	printf("String size: %d\n", leng);
	char mystring[leng];
	printf("Your string:\n");
	for(int i = 0; i < leng; i++){
		int num = (rand() % 128);
		char temp = num+'0';
		mystring[i] = temp;
		printf("%c ", mystring[i]);
	}	
	printf("\n");
	return 0;
}
