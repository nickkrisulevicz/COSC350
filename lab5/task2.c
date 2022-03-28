//Nick Krisulevicz
//COSC 350
//Lab 5
//03/27/2022
//task2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utmp.h>

//Function to open the utmp file. It returns the file descriptor
int openUtmpFile(){
	int utmpfd = open("/var/run/utmp", O_RDONLY);
	return utmpfd;
}

int main(){
	//Initialize a variable in the main function with the file descriptor
	int fd = openUtmpFile();
	//Print the file descriptor value in the console
	printf("File descriptor of utmp is: %d\n", fd);

	//Initialize the buffer to read from the utmp file
	char buff[200];
	int counter = 0;

	//Loop to steo through the file and print each line
	while(counter != sizeof(fd)){
		lseek(fd, counter, SEEK_SET);
		read(fd, buff, 1);
		printf("%s\n", buff);
		counter++;
	}

	//close the file
	close(fd);

	return 0;
}
