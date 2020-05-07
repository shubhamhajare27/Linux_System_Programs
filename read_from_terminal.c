#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_READ 20

char buffer[MAX_READ];

int main()
{
	int no;
	if((no=read(STDIN_FILENO,buffer,MAX_READ))==-1)
	{
		printf("Error\n");
		exit(-1);
	}
	printf("the string is %s %d",buffer,no);
	return 0;
}
