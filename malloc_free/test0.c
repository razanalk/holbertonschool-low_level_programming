#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	char *arr;
	unsigned int i;

	arr = create_array(10, 'A');

	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	for (i = 0; i < 10; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");

	free(arr);

	return (0);
}
