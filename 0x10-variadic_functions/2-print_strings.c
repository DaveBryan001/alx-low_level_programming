#include "variadic_functions.h"

/**
 * print_strings - Prints strings
 * @separator: A string to be printed between strings
 * @n: number of strings passed to the function
 * Return: return void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int i;
	va_list valist;

	va_start(valist, n);
	if (separator == NULL)
		separator = "";

	for (i = 0; i < n; i++)
	{
		str = va_arg(valist, char*);
		if (str == NULL)
			str = "(nil)";
		printf("%s", str);
		if (i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(valist);
}
