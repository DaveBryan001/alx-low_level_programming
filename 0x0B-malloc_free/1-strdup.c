#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
	char *strptr;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	strptr = (char *)malloc(sizeof(char) * (i + 1));

	if (strptr == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		strptr[j] = str[j];

	return (strptr);
}
