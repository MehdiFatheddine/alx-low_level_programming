#include <stdio.h>

/**
 * main - Entry point
 *
 * This function is the entry point of the program. It initializes some
 * variables and prints the value of a[2] after modifying the memory location
 * pointed to by p + 5.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 0; /* Initialize n to 0 */
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	/**
	 * -  write your line of code here...
	 *   Remember:
	 * - you are not allowed to use a
	 * - you are not allowed to modify p
	 * - only one statement
	 * - you are not allowed to code anything else than this line of code
	 */
	*(p + 5) = 98; /* Assign 98 to the memory location 5 integers away from p */
	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}
