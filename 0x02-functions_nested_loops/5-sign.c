#include <stdio.h>

/**
 * print_sign - Prints the sign of a number.
 * @n: The number to check.
 *
 * Return: 1 and prints '+' if n is greater than zero.
 *         0 and prints '0' if n is zero.
 *         -1 and prints '-' if n is less than zero.
 */
void print_sign(int n)
{
	if (n > 0)
	{
		putchar('+');
		putchar('\n');
	}
	else if (n < 0)
	{
		putchar('-');
		putchar('\n');
	}
	else
	{
		putchar('0');
		putchar('\n');
	}
}

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	int number = -5;

	print_sign(number);

	return 0;
}

