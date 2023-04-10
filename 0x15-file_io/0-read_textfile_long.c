#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Actual number of letters read and printed, 0 on failure
 **/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd; /* file descriptor */
	ssize_t rd, wr; /* number of bytes read and written */
	char *buffer; /* buffer to hold file contents */

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1)); /* allocate buffer memory */
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY); /* open file in read-only mode */
	if (fd == -1) /* check if open failed */
	{
		free(buffer);
		return (0);
	}

	rd = read(fd, buffer, letters); /* read up to 'letters' bytes from file */
	if (rd == -1) /* check if read failed */
	{
		free(buffer);
		close(fd);
		return (0);
	}

	buffer[rd] = '\0'; /* add null terminator to buffer */

	wr = write(STDOUT_FILENO, buffer, rd);
	/* write contents of buffer to standard output */

	if (wr == -1 || wr != rd)
	/* check if write failed or did not write the expected amount of bytes */
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer); /* free buffer memory */
	close(fd); /* close file descriptor */

	return (wr); /* return number of bytes written */
}
