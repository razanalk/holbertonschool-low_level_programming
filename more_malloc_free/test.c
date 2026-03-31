#include <stdio.h>
#include <stdlib.h>

void *_calloc(unsigned int nmemb, unsigned int size);

int main(void)
{
	char *a;

	a = _calloc(98, sizeof(char));
	if (a == NULL)
		return (1);

	printf("%s\n", a);

	free(a);
	return (0);
}
