#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 **/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, len;

	/* Return -1 if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Open the file in append mode and return -1 on failure */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is not NULL, write it to the file */
	if (text_content != NULL)
	{
		/* Calculate the length of the string */
		len = 0;
		while (text_content[len] != '\0')
			len++;

		/* Write text_content to the file and return -1 on failure */
		bytes_written = write(fd, text_content, len);
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	/* Close the file and return 1 on success */
	close(fd);
	return (1);
}

