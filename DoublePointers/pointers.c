#include <stdio.h>
#include <malloc.h>

//alloc_mem: allocated memory of size_mem bytes and stores in *myptr.
//params:
//	size_mem: interger value, number of bytes to be allocated.
//	myptr: double pointer, store the allocated memory in zero index.
//return:
//	nothing.	
void alloc_mem(int size_mem, void **myptr)
{
	if(size_mem > 0)
		*myptr = malloc(size_mem);
	printf("Allocated memory %p of size %d\n", *myptr, size_mem);
}

void main()
{
	char *ptr;
	alloc_mem(100, &ptr);
	printf("Starting memory %p \n", ptr);
	for(int i = 0; i <10 ; i++)
		ptr[i] = '0' + i;

	for(int j = 0; j < 10 ; j++)
		printf("At memory %p : %c \n", &ptr[j],ptr[j]);
}
