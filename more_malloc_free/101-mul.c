#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_digit - checks if string contains only digits
 * @s: input string
 * Return: 1 if true, 0 if false
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns length of string
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * errors - prints error and exits
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, i, j, carry, n1, n2;
	int *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();

	s1 = argv[1];
	s2 = argv[2];
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
		return (1);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = s1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = s2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
		_putchar('0');
	else
	{
		for (; i < len1 + len2; i++)
			_putchar(result[i] + '0');
	}

	_putchar('\n');

	free(result);

	return (0);
}
