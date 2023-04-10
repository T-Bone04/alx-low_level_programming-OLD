/**
 * get_endianness - Checks the endianness of the machine.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	/* Create a 2-byte array and set its first byte to 1 */
	unsigned short int num = 0x01;
	/* Cast the array to a pointer to a char */
	char *c = (char *)&num;
	/* If the first byte is 1, the machine is little endian;*/
	/* otherwise, it is big endian */
	return ((int)*c);
}
