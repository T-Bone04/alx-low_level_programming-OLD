/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: A pointer to the unsigned long int number to modify.
 * @index: The index of the bit to clear (starting from 0).
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int mask;

    /* Check if index is greater than the number of bits in unsigned long int */
    if (index >= (sizeof(unsigned long int) * 8))
        return (-1);

    /* Create a mask with only the bit at index set to 0 */
    mask = ~(1UL << index);

    /* Use bitwise AND to set the bit at index to 0 */
    *n &= mask;

    return (1);
}

