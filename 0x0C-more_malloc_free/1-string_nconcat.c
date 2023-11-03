#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - function that concatenates two strings.
 * @s1: first string
 * @s2: second string
 * @n: amount of bytes
 *
 * Return: returns a pointer to the newly allocated space in memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int st1, st2, str, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (st1 = 0; s1[st1] != '\0'; st1++)
		;

	for (st2 = 0; s2[st2] != '\0'; st2++)
		;

	if (n > st2)
		n = st2;

	str = st1 + n;

	s = malloc(str + 1);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < str; i++)
		if (i < st1)
			s[i] = s1[i];
		else
			s[i] = s2[i - st1];

	s[i] = '\0';

	return (s);
}
