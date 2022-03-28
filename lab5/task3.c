//Nick Krisulevicz
//COSC 350
//Lab 5
//03/27/2022
//task3.c

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utmp.h>
#include <sys/stat.h>
#include <sys/types.h>

char *myasctime(const struct tm *timeptr)
{
	//initialize arrays of strings for the days of the week and the months of the year
	char weekday[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	char month[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	char mytime[26];

	//print the time formatted in weekday, month, hours:minutes:seconds, years
	printf(mytime, "%s %s %2d %.2d:%.2d:%.2d %d", weekday[timeptr->tm_wday], month[timeptr -> tm_mon], timeptr -> tm_mday, 
		timeptr -> tm_hour, timeptr -> tm_min, timeptr -> tm_sec, timeptr -> tm_year + 1900);

	//return this time to the main function
	return mytime;
}


int main(int argc, char *argv[]){
	//initialize a temporary time variable and get value from time.h
	time_t timetemp;
	time(&timetemp);

	//create the time pointer from the struct
	struct tm *timeptr;
	timeptr = localtime(&timetemp);

	//print the time with a call to the myasctime function
	printf("The time is %s\n", myasctime(timeptr));
	
	return 0;
}
