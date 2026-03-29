#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	char *s;

	s = str_concat("Best ", "School");

	if (s == NULL)
	{
		printf("failed\n");
		return (1);
	}

	printf("%s\n", s);

	free(s);

	return (0);
}
