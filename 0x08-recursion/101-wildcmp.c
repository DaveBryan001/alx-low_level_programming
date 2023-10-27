#include "main.h"

/**
 * wildcmp -
 * @s1: first string
 * @s2: second string
 * Return: 1 if strings are identical, 0 if not
 */

int wildcmp(char *s1, char*s2)
{
	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);
	if *(s1
