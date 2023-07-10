#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
char *allocate_memory(char *file);
void close_descriptor(int fd);
/**
* allocate_memory - Allocates 1024 bytes of memory for a buffer.
* @file: The name of the file the buffer is storing characters for.
*
* Return: A pointer to the newly-allocated buffer.
*/
char *allocate_memory(char *file)
{
char *buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Cannot allocate memory for %s\n", file);
exit(99);
}
return (buffer);
}
/**
* close_descriptor - Closes a file descriptor.
* @fd: The file descriptor to be closed.
*/
void close_descriptor(int fd)
{
int result = close(fd);
if (result == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close file descriptor %d\n", fd);
exit(100);
}
}
/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success.
* Description: If the argument count is incorrect - exit code 97.
* If file_from does not exist or cannot be read - exit code 98.
* If file_to cannot be created or written to - exit code 99.
* If file_to or file_from cannot be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
int from, to, r, w;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = allocate_memory(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
while (r > 0)
{
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
w = write(to, buffer, r);
if (to == -1 || w == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot write to file %s\n", argv[2]);
free(buffer);
exit(99);
}
r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
}
free(buffer);
close_descriptor(from);
close_descriptor(to);
return (0);
}
