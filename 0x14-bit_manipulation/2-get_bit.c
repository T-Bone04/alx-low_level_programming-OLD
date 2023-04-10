/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The unsigned long int number to get the bit from.
 * @index: The index of the bit to get (starting from 0).
 *
 * Return: The value of the bit at the specified index,
 * or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

/* Check if index is greater than the number of bits in unsigned long int */
	if (index >= (sizeof(unsigned long int) * 8))
	return (-1);

/* Shift 1 by index to the left to get a mask with only the bit at index set */
	mask = 1UL << index;
	/* Use bitwise AND to check if the bit at index is set */
	if (n & mask)
	return (1);
		else
	return (0);
}
