#include "main.h"

/**
 * factorial - returns factorial of a given number
 * @n: number
 *
 * Return: returns -1 if an error is encountered
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));

}
