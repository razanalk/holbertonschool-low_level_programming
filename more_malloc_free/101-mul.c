#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - checks if string is digits
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
 * _strlen - length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * errors - prints error and exit
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiply big numbers
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, carry, n1, n2, *result, sum;

	if (argc != 3)
		errors();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		errors();

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
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
		printf("0");
	else
	{
		for (; i < len1 + len2; i++)
			printf("%d", result[i]);
	}
	printf("\n");

	free(result);
	return (0);
}
