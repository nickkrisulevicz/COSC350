//Nick Krisulevicz
//COSC 350
//Lab 4
//03/17/2022
//task2.c

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
	char printingstring;
	int charindex;
	int fileread = open(argv[1], O_RDONLY);
	
	if(fileread == -1) {
		printf("Could not read file!\n");
		return 0;
	}
	
	int i = 0;
	while (read(fileread, buffer, 1)) {
		printf("%s\n", buffer); 
		if(buffer[0] >= '0' && buffer[0] <= '9')
		charread[i++] = buffer[0];
	}
	charread[i] = '\0';
	printf("Character is: %s\n", charread);
	  
	sscanf(charread, "%d", &charindex);
	printf("Value of string in ASCII : %d \n", charindex);
	  
	charindex += 10;
	printf("Value plus ten is: %d \n", charindex);
	
	int stringleng = convIntToStr(&printingstring, charindex);
	printf("Length of numerical string is %d \n", stringleng);
	
	write(1, &printingstring, strlen(&printingstring) + 1);
	
	printf("\n");	
	close(fileread);

	return 0;
}
