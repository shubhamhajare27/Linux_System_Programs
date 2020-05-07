#include<stdio.h>
#include<gnu/libc-version.h>

int main()
{
	const char * str=gnu_get_libc_version();

	printf("%s",str);

	return 0;
}
