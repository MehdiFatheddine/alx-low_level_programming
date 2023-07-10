#include "main.h"
/**
* create_file - Creates a file.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to a string to write to the file.
* Return: If the function fails - -1.
* Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
int fd, w, len = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
while (text_content[len] != '\0')
len++;
}
fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);
w = write(fd, text_content, len);
close(fd);
if (w == -1 || (text_content != NULL && w != len))
return (-1);
return (1);
}
