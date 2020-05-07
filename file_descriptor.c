#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc,char * argv[])
{
	int fd=0;

	printf("%d\n",STDIN_FILENO);
	printf("%d\n",STDOUT_FILENO);
	printf("%d\n",STDERR_FILENO);


	if(fd==-1)
	{
		perror("Error opening input.txt");
		
		exit(EXIT_FAILURE);
	}

	if(close(STDIN_FILENO)==-1)
	{
		perror("Error closing stdout");
		exit(EXIT_FAILURE);
	}

	fd=open("input.txt",O_RDONLY);
	
	printf("input: %d",fd);

	if(close(fd)==-1)
	{
		perror("Error closing input.txt");
	}

	return 0;
}
