//Nick Krisulevicz
//COSC 350
//Lab 4
//03/17/2022
//task4.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char pworkdir[] = "/home/nickkrisulevicz/COSC350/lab4";
    char location[256];
    chdir(pworkdir);

    sprintf(location, "%s/Dir1", pworkdir);
    mkdir(location, 0777);
    sprintf(location, "%s/Dir2", pworkdir);
    mkdir(location, 0777);
    sprintf(location, "%s/Dir21", location);
    mkdir(location, 0777);
    sprintf(location, "%s/hello", location);

    char buf;
    int fd1;
    int fd2;

    fd1 = open("hello", O_RDONLY);
    fd2 = open(location, O_CREAT | O_WRONLY, 0777);
    while(read(fd1, &buf, 1) > 0){
        write(fd2, &buf, 0);
    }

    char linkdir[256];

    sprintf(location, "%s/Dir1/linkDir21", pworkdir);
    sprintf(linkdir, "%s/Dir2/Dir21", pworkdir);

    symlink(location, linkdir);

    sprintf(location, "%s/Dir1/linkHello", pworkdir);
    sprintf(linkdir, "%s/Dir2/Dir21/hello", pworkdir);

    symlink(location, linkdir);

    close(fd1);
    close(fd2);

    return 0;
}
