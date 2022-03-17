//Nick Krisulevicz
//COSC 350
//Lab 4
//03/17/2022
//task1.c

#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int convIntToStr(char* str, int x) {
	sprintf(str, "%d", x);
	return(strlen(str));
}

int main(int argc, char *argv[]) { 
	if(argc == 2) {
		printf("Input file is: %s\n", argv[1]);
	}

	else if(argc > 2) {
		printf("Only one argument is allowed!\n");
	}

	else {
		printf("You didn't provide an argument!\n");
		return 0;
	}

	char buffer[80];
	char charread[80];
	char buffercopy[80];
	
	int fileread = open(argv[1], O_RDONLY);
	int filewrite = open("hog.txt", O_CREAT | O_WRONLY, 0777);
	
	if (fileread == -1) {
		printf("Could not read input file!\n");
		return 0;
	}

	if (filewrite == -1){
		printf("Could not read output file!\n");
		return 0;
	}
	int i = 0;
	int tempbuf;
	while (read(fileread, buffer, 1)) {
		printf("%s\n", buffer); 
		if(buffer[0] >= '0' && buffer[0] <= '9')
			charread[i++] = buffer[0];	
		write(filewrite, (int) buffer, 1);
	}

	printf("\n");
	close(fileread);
	close(filewrite);
	
	return 0;
}
