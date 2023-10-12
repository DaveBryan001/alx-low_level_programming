#include "function_pointers.h"

/**
 * int_index - function that searches for an integer
 * @array: integer array
 * @size: number of elements in the array
 * @cmp: pointer to the function
 *
 * Return: index of the first element for which the cmp
 * function does not return 0. If no elements matches,
 * return -1. 
 * If size <= 0, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		if (size <= 0)
			return (-1);

		for (i = 0; i < size; i++)
			if (cmp(array[i]))
				return (i);
	}

	return (-1);
}
