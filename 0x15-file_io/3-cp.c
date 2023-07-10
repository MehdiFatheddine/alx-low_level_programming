#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *allocate_buffer(void);
void close_file_descriptor(int fd);
/**
* allocate_buffer - Allocates a buffer of 1024 bytes.
* @file: The name of the file the buffer is storing characters for.
*
* Return: A pointer to the newly allocated buffer.
*/
char *allocate_buffer(void)
{
char *buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
fprintf(stderr, "Error: Unable to allocate memory\n");
exit(99);
}
return buffer;
}
/**
* close_file_descriptor - Closes a file descriptor.
* @fd: The file descriptor to be closed.
*/
void close_file_descriptor(int fd)
{
if (close(fd) == -1)
{
fprintf(stderr, "Error: Unable to close file descriptor %d\n", fd);
exit(100);
}
}
/**
* main - Copies the contents of one file to another.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: Exit codes:
*  97 - Incorrect number of arguments.
*  98 - Unable to read from file_from or file does not exist.
*  99 - Unable to write to file_to.
*  100 - Unable to close file descriptor.
*/
int main(int argc, char *argv[])
{
int file_from, file_to, bytes_read, bytes_written;
char *buffer;
if (argc != 3)
{
fprintf(stderr, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = allocate_buffer();
file_from = open(argv[1], O_RDONLY);
bytes_read = read(file_from, buffer, 1024);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
while (bytes_read > 0)
{
if (file_from == -1 || bytes_read == -1)
{
fprintf(stderr,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
bytes_written = write(file_to, buffer, bytes_read);
if (file_to == -1 || bytes_written == -1)
{
fprintf(stderr,
"Error: Can't write to file %s\n", argv[2]);
free(buffer);
exit(99);
}
bytes_read = read(file_from, buffer, 1024);
file_to = open(argv[2], O_WRONLY | O_APPEND);
}
free(buffer);
close_file_descriptor(file_from);
close_file_descriptor(file_to);
return 0;
}
