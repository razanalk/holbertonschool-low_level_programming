#include "main.h"
#include <stdlib.h>

/**
 * is_digit - checks if string contains only digits
 * @s: string
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
 * @s: string
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
	int i;
	char *msg = "Error\n";

	for (i = 0; msg[i]; i++)
		_putchar(msg[i]);

	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, n1, n2, carry, sum;
	int *result;

	if (argc != 3)
		errors();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		errors();

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = malloc(sizeof(int) * (len1 + len2));
	if (!result)
		return (1);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = result[i + j + 1] + (n1 * n2) + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
	{
		_putchar('0');
	}
	else
	{
		for (; i < len1 + len2; i++)
			_putchar(result[i] + '0');
	}

	_putchar('\n');

	free(result);

	return (0);
}
