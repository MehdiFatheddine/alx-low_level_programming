#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _strlen - Returns the length of a string.
 * @str: The string to get the length of.
 *
 * Return: The length of @str.
 */
size_t _strlen(char *str)
{
size_t i;
for (i = 0; str[i];)
i++;
return (i);
}
/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly-allocated duplicate string.
 *         NULL if memory allocation fails or str is NULL.
 */
char *_strdup(char *str)
{
char *dup;
size_t len, i;
if (str == NULL)
return (NULL);
len = _strlen(str);
dup = malloc(sizeof(char) * (len + 1));
if (dup == NULL)
return (NULL);
for (i = 0; str[i]; i++)
dup[i] = str[i];
dup[i] = '\0';
return (dup);
}
/**
 * _strcat - Concatenates two strings.
 * @dest: The string to concatenate to.
 * @src: The string to be concatenated.
 *
 * Return: A pointer to the concatenated string.
 *         NULL if memory allocation fails or dest/src are NULL.
 */
char *_strcat(char *dest, char *src)
{
size_t dest_len, src_len, i, j;
if (dest == NULL || src == NULL)
return (NULL);
dest_len = _strlen(dest);
src_len = _strlen(src);
for (i = dest_len, j = 0; j < src_len; i++, j++)
dest[i] = src[j];
dest[i] = '\0';
return (dest);
}
/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the newly-allocated concatenated string.
 *         NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
char *concat;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
concat = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 1));
if (concat == NULL)
return (NULL);
_strcat(concat, s1);
_strcat(concat, s2);
return (concat);
}
/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
char *s;
s = str_concat("Holberton ", "School");
printf("%s\n", s);
free(s);
s = str_concat(NULL, NULL);
printf("%s\n", s);
free(s);
s = str_concat(NULL, "School");
printf("%s\n", s);
free(s);
s = str_concat("Holberton ", NULL);
printf("%s\n", s);
free(s);
s = str_concat("", "School");
printf("%s\n", s);
free(s);
return (0);
}
