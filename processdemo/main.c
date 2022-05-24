#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int pid;
	pid = getpid();
	int fi;
	fi = fork();
	if(fi == 0){
		int i;
		i = fork();
		if(i == 0){
			printf("%d %d\ni == 0\n", getpid(), getppid());
		}
		else{
			printf("%d %d\ni != 0\n", getpid(), fi);
		}
	}
	else{
		fi = fork();
		printf("%d\nfi =! 0\n", fi);
	}
	return 0;
}

