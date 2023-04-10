#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* function prototypes */
void validate_input(int argc);
void copy_file(const char *from_path, const char *to_path);
void set_permissions(const char *path);

int main(int argc, char *argv[]) {
    /* validate input */
    validate_input(argc);

    /* copy file */
    copy_file(argv[1], argv[2]);

    /* set permissions */
    set_permissions(argv[2]);

    return 0;
}

/* validate input */
void validate_input(int argc) {
    /* check for correct number of arguments */
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
}

/* copy file */
void copy_file(const char *from_path, const char *to_path) {
    int fd_from, fd_to, n_read;
    char buf[BUFFER_SIZE];

    /* open the source file */
    if ((fd_from = open(from_path, O_RDONLY)) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_path);
        exit(98);
    }

    /* truncate the destination file if it already exists */
    if ((fd_to = open(to_path, O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_path);
        exit(99);
    }

    /* copy the contents of the source file to the destination file */
    while ((n_read = read(fd_from, buf, BUFFER_SIZE)) > 0) {
        if (write(fd_to, buf, n_read) != n_read) {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_path);
            exit(99);
        }
    }

    /* check for read error */
    if (n_read == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_path);
        exit(98);
    }

    /* close file descriptors */
    if (close(fd_from) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }
    if (close(fd_to) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }
}

/* set file permissions */
void set_permissions(const char *path) {
    struct stat st;

    /* get file information */
    if (stat(path, &st) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't get file information for %s\n", path);
        exit(99);
    }

    /* set file permissions */
    if (chmod(path, st.st_mode | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't set permissions for %s\n", path);
        exit(99);
    }
}
