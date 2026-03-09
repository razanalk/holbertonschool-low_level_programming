#include "main.h"

/**
 * helper - checks if number is prime
 * @n: number
 * @i: divisor
 * Return: 1 if prime, 0 otherwise
 */

int helper(int n, int i)
{
	if (i == n)
		return (1);

	if (n % i == 0)
		return (0);

	return (helper(n, i + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: number
 * Return: 1 if prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (helper(n, 2));
}
