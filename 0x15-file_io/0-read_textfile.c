#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H

#endif


/**
 * read_file_into_buffer - Reads a file into a buffer
 *
 * @filename: Name of the file to read
 * @letters: Number of letters to read
 *
 * Return: Pointer to buffer containing file contents, NULL on failure
 **/
char *read_file_into_buffer(const char *filename, size_t letters)
{
	int fd; /* file descriptor */
	ssize_t rd; /* number of bytes read */
	char *buffer; /* buffer to hold file contents */

	if (filename == NULL)
		return (NULL);

	buffer = malloc(sizeof(char) * (letters + 1)); /* allocate buffer memory */
	if (buffer == NULL)
		return (NULL);

	fd = open(filename, O_RDONLY); /* open file in read-only mode */
	if (fd == -1) /* check if open failed */
	{
		free(buffer);
		return (NULL);
	}

	rd = read(fd, buffer, letters); /* read up to 'letters' bytes from file */
	if (rd == -1) /* check if read failed */
	{
		free(buffer);
		close(fd);
		return (NULL);
	}

	buffer[rd] = '\0'; /* add null terminator to buffer */

	close(fd); /* close file descriptor */

	return (buffer); /* return buffer pointer */
}

/**
 * print_buffer_to_stdout - prints a buffer to the standard output (STDOUT)
 * @buf: pointer to the buffer to print
 * @size: size of the buffer in bytes
 * @letters: number of letters to print from the buffer
 *
 * Return: the number of letters printed
 */
ssize_t print_buffer_to_stdout(char *buf, ssize_t size, ssize_t letters)
{
	ssize_t wr; /* variable to store the number of bytes written */

	/* check if the buffer is null */
	if (!buf)
		return (0);

	/* check if the requested num of letters is > the size of the buffer */
	if (letters > size)
		letters = size;

	/* write the specified number of letters to the standard output (STDOUT) */
	wr = write(STDOUT_FILENO, buf, letters);

	/* check for errors in the write operation */
	if (wr == -1 || wr != letters)
		return (0);

	/* return the number of bytes written */
	return (wr);
}

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
	char *buffer; /* buffer to hold file contents */
	ssize_t bytes_read; /* number of bytes read */

	buffer = read_file_into_buffer(filename, letters); /* read file into buffer */
		if (buffer == NULL)
		return (0);

	bytes_read = print_buffer_to_stdout(buffer, strlen(buffer), letters);
	/* print buffer to standard output */

	free(buffer);
	return (bytes_read);
}
