#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

/**
 * Prints usage information for the program.
 */
void print_usage(void)
{
    dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
}

/**
 * Handles an error by printing an error message and exiting with an error code.
 *
 * @param err_num the error code to exit with
 * @param file_name the name of the file associated with the error, or NULL if not applicable
 */
void handle_error(int err_num, char *file_name)
{
    switch (err_num)
    {
        case 97:
            dprintf(STDERR_FILENO, "Error: Invalid arguments\n");
            print_usage();
            break;
        case 98:
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
            break;
        case 99:
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
            break;
        case 100:
            dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
            break;
        default:
            break;
    }

    exit(err_num);
}

/**
 * Copies the contents of one file to another.
 *
 * @param file_from the name of the file to copy from
 * @param file_to the name of the file to copy to
 */
void copy_file(char *file_from, char *file_to)
{
    int fd_from, fd_to, rd, wr;
    char *buf;

    /* Allocate memory for buffer */
    buf = malloc(sizeof(char) * BUF_SIZE);
    if (!buf)
        handle_error(99, file_to);

    /* Open file_from for reading */
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        handle_error(98, file_from);

    /* Open file_to for writing, truncate if it exists */
    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1)
        handle_error(99, file_to);

    /* Read BUF_SIZE bytes at a time from file_from and write to file_to */
    while ((rd = read(fd_from, buf, BUF_SIZE)) > 0)
    {
        wr = write(fd_to, buf, rd);
        if (wr != rd)
            handle_error(99, file_to);
    }

    /* Check for read error */
    if (rd == -1)
        handle_error(98, file_from);

    /* Free buffer memory */
    free(buf);

    /* Close file descriptors */
    if (close(fd_from) == -1)
        handle_error(100, NULL);

    if (close(fd_to) == -1)
        handle_error(100, NULL);
}

/**
 * Main function of the program that takes file names as arguments and calls the copy_file function.
 *
 * @param argc the number of command line arguments
 * @param argv an array of strings containing the command line arguments
 * @return 0 if the program exits successfully, otherwise an error code
 */
int main(int argc, char **argv)
{
    /* Check for correct number of arguments */
    if (argc != 3)
        handle_error(97, NULL);

    /* Call copy_file function */
    copy_file(argv[1], argv[2]);

    return 0;
}

