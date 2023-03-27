#include "main.h"

/**
 * hexadecimal - prints hexidecimal value of integers
 *
 * @n: input non-printable character as integer
 *
 */

void hexadecimal(unsigned int n)
{
	int i = 0, remainder = 0;
	char *array = malloc(INT_MAX);

	if (array == NULL)
		return;
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder > 9)
			array[i] = (remainder - 10) + 'A';
		else
			array[i] = remainder + '0';
		n /= 16;
		i++;
	}
	if (i == 1)
		_putchar('0');
	array[i] = '\0';
	for (i = (i - 1); i >= 0; i--)
	{
		_putchar(array[i]);
	}
	free(array);
}

/**
 * print_binary - Converts a number from base 10 to binary
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: The length of the number printed
 */

int print_binary(va_list ap)
{
	int dig = 0, len = 0;
	unsigned long binary = 0, num = 0;
	unsigned long n = va_arg(ap, int);

	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	while (n > 0)
	{
		num = n;
		dig++;
		binary += n % 2;
		n /= 2;
		if ((num == 1) && (n == 1))
			break;
		binary *= 10;
	}
	binary /= 10;
	len = dig;
	for (; dig > 0; dig--)
	{
		_putchar((binary % 10) + '0');
		binary /= 10;
	}
	return ((len) - 1);
}

/**
 * print_octal - prints octal value of integers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: Number of symbols printed to stdout
 */

int print_octal(va_list ap)
{
	int dig = 0, len = 0;
	unsigned long octal = 0;
	unsigned int n = va_arg(ap, int);

	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	while (n > 0)
	{
		dig++;
		octal += n % 8;
		n /= 8;
		octal *= 10;
	}
	octal /= 10;
	len = dig;
	for (; dig > 0; dig--)
	{
		_putchar((octal % 10) + '0');
		octal /= 10;
	}
	return ((len) - 1);
}
/**
 * print_unsigned - prints unsignedintegers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: character count from this function
 */

int print_unsigned(va_list ap)
{
	int digits = 1, divider = 1, j = 0, j2 = 0;
	unsigned int n = va_arg(ap, int);
	unsigned int num = n;

	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	/* counts number of digits by increasing count and dividing by 10 */
	while ((num / 10) != 0)
	{
		digits++;
		num /= 10;
	}
	/* loops through number from last digit to largest digit */
	for (j = (digits - 1); j >= 0; j--)
	{
		divider = 1;
		for (j2 = 0; j2 < j; j2++)
			divider = divider * 10;
		_putchar((n / divider) + '0');
		n = n % divider;
	}
	return (digits - 1);
}
