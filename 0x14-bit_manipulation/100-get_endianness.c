#include "main.h"
/**
 * get endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
int num = 1;
char *ptr = (char *)&num;
return (*ptr);
}
