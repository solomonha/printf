#include "main.h"

/**
 * print_char - Printing character
 * @ap: argument pointer
 * Return: character
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	_putchar(c);
	return (0);
}

/**
 * print_int - prints integers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: character count from this function
 */

int print_int(va_list ap)
{
	int dig = 1, div = 1;
	int n = va_arg(ap, int);
	int num = n, i = 0, j = 0, neg = 0;

	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	/* counts number of digits by increasing count and dividing by 10 */
	while ((num / 10) != 0)
	{
		dig++;
		num /= 10;
	}
	/* loops through number from last digit to largest digit */
	for (i = (dig - 1); i >= 0; i--)
	{
		div = 1;
		for (j = 0; j < i; j++)
			div = div * 10;
		if (n < 0)
		{
			_putchar('-');
			_putchar((0 - (n / div)) + '0');
			n = n % div;
			n = 0 - n;
			neg = 1;
		}
		else
		{
			_putchar((n / div) + '0');
			n = n % div;
		}
	}
	return (dig - 1 + neg);
}

/**
 * print_string - Printing string
 * @ap: argument point
 * Return: string
 */
int print_string(va_list ap)
{
	int i;
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_perc - prints percent sign
 *
 * Return: character count from this function
 */

int print_perc(void)
{
	_putchar('%');
	return (1);
}
/**
 * print_S - prints string with non-printable character as hexidecimal value
 *
 * @ap: argument pointer to next argument, string to be printed
 *
 * Return: character count from this function
 */

int print_S(va_list ap)
{
	int i = 0, j = 0, count = 0;
	char *str = "(null)";
	char *s = va_arg(ap, char *);

	if (s == NULL)
	{
		for (j = 0; str[j]; j++)
			_putchar(str[j]);
		return (-1);
	}
	for (i = 0; s[i]; i++, count++)
	{
		if (s[i] >= 32 && s[i] <= 126)
			_putchar(s[i]);
		else
		{
			_putchar('\\');
			_putchar('x');
			hexadecimal(s[i]);
			count += 3;
		}
	}
	return (count - 1);
}

/**
 * print_hexadecimalX - prints hexadecimal value of integers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: character count from this function
 */

int print_hexadecimalX(va_list ap)
{
	int i = 0, remain = 0, save_digits = 0;
	char *array = malloc(INT_MAX);
	unsigned int n = va_arg(ap, int);

	if (array == NULL)
	{
		return (0);
	}
	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	while (n > 0)
	{
		remain = n % 16;
		if (remain > 9)
			array[i] = (remain - 10) + 'A';
		else
			array[i] = remain + '0';
		n /= 16;
		i++;
	}
	array[i] = '\0';
	save_digits = (i - 1);
	for (i = (i - 1); i >= 0; i--)
	{
		_putchar(array[i]);
	}
	free(array);
	return (save_digits - 1);
}

/**
 * print_hexadecimal - prints hexidecimal value of integers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: character count from this function
 */

int print_hexadecimalx(va_list ap)
{
	int i = 0, remain = 0, save_digits = 0;
	char *array = malloc(INT_MAX);
	unsigned int n = va_arg(ap, int);

	if (array == NULL)
	{
		return (0);
	}
	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	while (n > 0)
	{
		remain = n % 16;
		if (remain > 9)
			array[i] = (remain - 10) + 'a';
		else
			array[i] = remain + '0';
		n /= 16;
		i++;
	}
	array[i] = '\0';
	save_digits = (i - 1);
	for (i = (i - 1); i >= 0; i--)
	{
		_putchar(array[i]);
	}
	free(array);
	return (save_digits - 1);
}
