#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a duplicated string
 * @str: string to duplicate
 *
 * Return: pointer or NULL
 */

char *_strdup(char *str)
{
	char *copy;
	int len = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = malloc(len + 1);

	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}
