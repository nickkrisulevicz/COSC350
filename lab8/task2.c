//Nick Krisulevicz
//COSC 350
//Lab 8
//04/28/2022
//task2.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int main(){
	pid_t pid;
	pid = fork();

	if(pid == 0){
		int fd1;
		fd1 = open("foo.txt", O_CREAT | O_WRONLY);
		write(fd1, "Hi, Mom", 8);
		close(fd1);
		exit(0);
	}

	else if(pid > 0){
		wait(NULL);
		int fd2;
		char buf[8];
		fd2 = open("foo.txt", O_RDONLY);
		printf("My son said ");
		read(fd2, buf, 8);
		write(1, buf, 8);
		printf("\n");
		close(fd2);
		exit(0);
	}
}
