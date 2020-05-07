#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int fd=open("A.txt",O_RDWR);

	off_t first=lseek(fd,0,SEEK_CUR);

	printf("first:- %ld\n",first);

	first=lseek(fd,0,SEEK_END);

	printf("last:- %ld\n",first);

	first=lseek(fd,10,SEEK_END);

	printf("current:- %ld\n",first);
	
	write(fd,"HAJARE",7);
	
	return 0;
}
