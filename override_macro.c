#include<stdio.h>

#define BUF_SIZE 0
#ifdef BUF_SIZE
#undef BUF_SIZE
#define BUF_SIZE 12
#endif

int main()
{
	printf("BUF_SIZE %d",BUF_SIZE);

	return 0;
}
