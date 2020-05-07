#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	/* open existing file for reading */

	int fd1=open("A.txt",O_RDONLY);

	if(fd1==-1)
	{
		printf("Error opening file");
		exit(-1);
	}
	
	printf("\n A.txt is opened");

	/* Open new or existing file for reading and writing, truncating to zero
bytes; file permissions read+write for owner, nothing for all others */

	int fd2=open("B.txt",O_CREAT | O_RDWR | O_TRUNC ,S_IRUSR | S_IWUSR);

	if(fd2==-1)
	{
		printf("Error opening file");
		exit(-1);
	}
	
	printf("\nB.txt is opened");

	/* Open new or existing file for writing; writes should always
append to end of file */

	int fd3=open("C.txt",O_CREAT | O_WRONLY | O_TRUNC | O_APPEND , S_IRUSR | S_IWUSR);

	if(fd3==-1)
	{
		printf("Error opening file");
		exit(-1);
	}

	printf("\nC.txt is opened\n");

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
