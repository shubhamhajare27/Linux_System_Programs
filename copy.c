#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#ifndef BUF_SIZE	//If BUF_SIZE is not in any header file then only declare
#define BUF_SIZE 1024
#endif

int main(int argc,char * argv[])
{
	int inputFd=0;
	int outputFd=0;
	int openFlags=0;
	mode_t filePerms;
	char buff[BUF_SIZE];
	ssize_t numRead;

	if(argc != 3 || strcmp(argv[1],"--help")==0)
	{
		printf("copy old-file new-file\n");
		
		return 0;
	}

	inputFd=open(argv[1],O_RDONLY);

	if(inputFd==-1)
	{
		perror("Error opening input file ");
	}

	openFlags= O_CREAT | O_WRONLY | O_TRUNC;

	filePerms= S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	outputFd=open(argv[2],openFlags,filePerms);

	if(outputFd==-1)
	{
		perror("Error opening output file ");
	}

	while((numRead = read(inputFd,buff,BUF_SIZE)) > 0)
	{
		if(write(outputFd,buff,numRead) != numRead)
		{
			perror("Could not write whole file");
		}
	}

	if(numRead==-1)
	{
		perror("Error ");
	}

	if(close(inputFd)==-1)
	{
		perror("close input");
	}
	if(close(outputFd)==-1)
	{
		perror("close output");
	}

	exit(EXIT_SUCCESS);

	return 0;
}
