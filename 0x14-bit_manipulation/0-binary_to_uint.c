#include "main.h"
#include <stddef.h>
/**
* binary_to_uint - converts a binary number to unsigned int
* @b: string containing the binary number
*
* Return: the converted number
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int decimal_value = 0;
if (b == NULL)
return (0);
for (; *b != '\0'; b++)
{
if (*b < '0' || *b > '1')
return (0);
decimal_value = (decimal_value << 1) + (*b - '0');
}
return (decimal_value);
}
