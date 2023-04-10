#include <stdio.h>

/**
 * print_binary - Prints the binary representation of
 * a number @n: The number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
    /* Variable declaration */
	unsigned long int mask = 1; /* Bit mask to isolate the rightmost bit */

    /* Find the most significant bit in the number */
	while (mask < n)
		mask = (mask << 1) | 1;

    /* Print the binary representation of the number */
	while (mask > 0)
	{
	if (n & mask)
	putchar('1');
	else
	putchar('0');

	mask = mask >> 1; /* Shift the mask to the right */
	}
}
