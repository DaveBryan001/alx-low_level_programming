#include <stdio.h>

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number in which the bit will be set.
 * @index: The index of the bit to set (starting from 0).
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    /* Check if the pointer is valid */
    if (n == NULL)
        return -1;

    /* Shift 1 to the left by the index positions and perform bitwise OR with *n */
    *n |= (1UL << index);

    return 1;
}

int main(void)
{
    unsigned long int num = 42;
    unsigned int bit_index = 2;

    int result = set_bit(&num, bit_index);

    if (result == 1)
        printf("Bit at index %u set to 1: %lu\n", bit_index, num);
    else
        printf("Error: Invalid bit index or null pointer\n");

    return 0;
}

