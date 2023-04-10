#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes text to it
 * @filename: Name of the file to create
 * @text_content: Text to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written = 0, text_size = 0;

	if (!filename) /* Check if filename is NULL */
		return (-1);

	if (text_content) /* Find the size of the text to write */
	{
		while (text_content[text_size])
			text_size++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	/* Create or truncate file */

	if (fd == -1) /* Check if file could not be created or truncated */
		return (-1);

	if (text_content) /* Write text to the file */
		bytes_written = write(fd, text_content, text_size);

	close(fd);

	if (bytes_written == -1) /* Check if writing to file failed */
		return (-1);

	return (1);
}
