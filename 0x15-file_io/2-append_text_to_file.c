#include "main.h"
/**
 * append_text_to_file - Appends the provided text to the end of a file.
 * @filename: Pointer to the name of the target file.
 * @text_content: The content to be added at the end of the file.
 * Return: -1 if the function fails or if the filename is NULL.
 * -1 if the file does not exist or if the user lacks write permissions.
 * Otherwise, returns 1 upon success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, w, len = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
while (text_content[len] != '\0')
len++;
}
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);
w = write(fd, text_content, len);
close(fd);
if (w == -1)
return (-1);
return (1);
}
