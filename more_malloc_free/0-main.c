#include <stdio.h>
#include <stdlib.h>

void *malloc_checked(unsigned int b);

int main(void)
{
	char *c;

	c = malloc_checked(1024);
	printf("%p\n", (void *)c);

	free(c);

	return (0);
}
