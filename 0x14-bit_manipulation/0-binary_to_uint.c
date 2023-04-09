#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned integer
 *
 * @b: Pointer to a string containing a binary number
 *
 * Return: The converted unsigned integer, or 0 if b contains invalid characters
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0; /* Initialize result variable to 0 */
	int index = 0; /* Initialize index variable to 0 */

	if (b == NULL) /* Check if b is NULL */
		return (0); /* Return 0 if b is NULL */

	while (b[index] != '\0') /* Loop through each character in b until the null terminator is reached */
	{
		if (b[index] != '0' && b[index] != '1') /* Check if the current character is not a valid binary digit */
			return (0); /* Return 0 if the current character is not a valid binary digit */

		result <<= 1; /* Shift the current value of result one bit to the left */
		if (b[index] == '1') /* If the current character is a 1 */
			result += 1; /* Add 1 to the current value of result */

		index++; /* Increment the index variable to move to the next character in b */
	}

	return (result); /* Return the final converted value of result */
}
