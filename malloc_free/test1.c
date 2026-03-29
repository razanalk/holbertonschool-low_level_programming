#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	char *copy;

	copy = _strdup("Razan");

	if (copy == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	printf("Original: Razan\n");
	printf("Copy: %s\n", copy);

	free(copy);

	return (0);
}
