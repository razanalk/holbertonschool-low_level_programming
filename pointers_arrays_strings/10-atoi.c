#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 * Return: integer
 */

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');

			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				break;
		}

		i++;
	}

	return (num * sign);
}
