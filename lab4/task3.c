//Nick Krisulevicz
//COSC 350
//Lab 4
//03/17/2022
//task3.c

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int palind(int fd1, int fd2){
	char buf;
	char string1[sizeof(fd1)];
	char string2[sizeof(fd2)];

	while (fd1 != EOF){
		string1 = read(

}

int main(int argc, char* argv[]){
	int filedes1 = open(argv[1], O_RDONLY);
	int filedes2 = open(argv[1], O_RDONLY);

	int palindrome = palind(filedes1, filedes2);

	if(palindrome == 0)
		printf("File does not contain a palindrome!\n");
	else if(palindrome == 1)
		printf("File contains a palindrome!\n");
	else
		printf("Error occurred\n");

	close(filedes1);
	close(filedes2);

	return 0;
}
