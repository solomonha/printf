#include "main.h"

/**
 * print_rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
int print_rot13(va_list ap)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ap, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return (i);
}

/**
 * print_reverse - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_reverse(va_list ap)
{
        char *x = va_arg(ap, char*), *nil_string = "(null)";
	int y, len, len2 = string_length(nil_string);

	if (x == NULL)
	{
		for (y = 0; nil_string[y]; y++)
			_putchar(nil_string[y]);
		return (len2 - 1);
	}
	len = string_length(x);
	for (y = (len - 1); y >= 0 ; y--)
		_putchar(x[y]);
	return (len - 1);
}

/**
 * string_compare - compares two strings
 * @s1: input string 1
 *
 * @s2: input string 2
 *
 * Return: integer
 */

int string_compare(const char *s1, char *s2)
{
	int i, r;

	i = 0;

	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		r = 0;
	}
	else
	{
		r = s1[i] - s2[i];
	}
	return (r);
}

/**
 * string_length - determines the length of a string
 * @s: input character string to determine length of
 *
 * Return: integer count of length
 */

int string_length(char *s)
{
	int i = 0;

	for (i = 0; s[i]; i++)
		continue;
	return (i);
}
