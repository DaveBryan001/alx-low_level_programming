#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int size = sizeof(n) * 8;
	unsigned long int bit = 1;

	bit <<= (size - 1);

	while (bit > 0)
	{
		if (n & bit)
			_putchar('1');
		else
			_putchar('0');
		bit >>= 1;
	}


	_putchar('\n');
}

