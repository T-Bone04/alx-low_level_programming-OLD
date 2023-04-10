/**
 * flip_bits - Returns the number of bits you would
 * need to flip to get from one
 * number to another.
 * @n: The first unsigned long int number.
 * @m: The second unsigned long int number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask;
	unsigned int num_bits_to_flip = 0;

	/* XOR n and m to get a number with all differing bits set to 1 */
	mask = n ^ m;

	/* Count the num of set bits in the mask using Brian Kernighan's algorithm */
	while (mask != 0)
	{
		mask &= (mask - 1);
		num_bits_to_flip++;
	}

	return (num_bits_to_flip);
}
