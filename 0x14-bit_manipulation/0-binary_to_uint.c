/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a pointer to a string of 0 and 1 characters representing a binary number
 *
 * Return: the converted unsigned int, or 0 if `b` is NULL
 * or contains non-binary characters
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;	/* variable to store the converted unsigned int */
	int i = 0;	/* counter variable for iterating through the binary string */

	/* check for NULL input */
	if (!b)
		return (0);

	/* iterate through the binary string */
	while (b[i])
	{
		/* check for non-binary characters */
		if (b[i] != '0' && b[i] != '1')
			return (0);

		/* shift result left and add the current binary digit */
		result <<= 1;
		result += b[i] - '0';

		i++;	/* increment counter */
	}

	return (result);	/* return the converted unsigned int */
}
