#include "main.h"
/**
* print_binary - prints the binary equivalent of a decimal number
* @n: number to print in binary
*/
void print_binary(unsigned long int n)
{
int i;
int count = 0;
unsigned long int mask = 1UL << 63;
for (i = 0; i < 64; i++)
{
if (n & mask)
{
_putchar('1');
count++;
}
else if (count > 0)
{
_putchar('0');
}
mask >>= 1;
}
if (count == 0)
{
_putchar('0');
}
}
