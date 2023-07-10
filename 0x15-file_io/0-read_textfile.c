#include "main.h"
#include <stdlib.h>
/**
* read_textfile - Read text file and print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: Actual number of bytes read and printed
*         0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
int fd;
ssize_t w = 0, t;
if (filename == NULL)
return (0);
fd = open(filename, 0);
if (fd == -1)
return (0);
buf = (char *)malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}
t = read(fd, buf, letters);
if (t != -1)
w = write(1, buf, t);
free(buf);
close(fd);
return (w);
}
