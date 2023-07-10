#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *allocate_buffer(void);
void close_file_descriptor(int fd);
/**
 * allocate_buffer - Dynamically allocates a buffer of size 1024 bytes.
 * Return: A pointer to the newly allocated buffer, or NULL on failure.
 */
char *allocate_buffer(void)
{
char *buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
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
int result = close(fd);
if (result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
exit(100);
}
}
/**
* main - Copies the contents of one file to another.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success.
* Description: Exit codes:
*  97 - Incorrect number of arguments.
*  98 - Unable to read from file_from or file does not exist.
*  99 - Unable to write to file_to.
*  100 - Unable to close file descriptor.
*/
int main(int argc, char *argv[])
{
int file_from, file_to, read_bytes, write_bytes;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = allocate_buffer();
file_from = open(argv[1], O_RDONLY);
read_bytes = read(file_from, buffer, 1024);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
while (read_bytes > 0)
{
if (file_from == -1 || read_bytes == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
write_bytes = write(file_to, buffer, read_bytes);
if (file_to == -1 || write_bytes == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to file %s\n", argv[2]);
free(buffer);
exit(99);
}
read_bytes = read(file_from, buffer, 1024);
file_to = open(argv[2], O_WRONLY | O_APPEND);
}
free(buffer);
close_file_descriptor(file_from);
close_file_descriptor(file_to);
return 0;
}
