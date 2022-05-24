#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	fd = open("aaa", O_CREAT | O_RDWR);
	char bufcont = 'a';
	char *buf = &bufcont;
	for(int i = 0; i < 1000; i++){
		write(fd, buf, 1);
	}
	bufcont = 'b';
	buf = &bufcont;
	for(int i = 0; i < 100; i++){
		write(fd, buf, 1);
	}
	bufcont = 'c';
	buf = &bufcont;
	for(int i = 0; i < 557; i++){
		write(fd, buf, 1);
	}
	close(fd);
	exit(0);
}
