#include "main.h"
/**
 * _printf - function to print string, formatting based on type of argument
 * @format:  A string containing all the desired characters.
 *
 * Return: int count of how many characters were printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0, count = 0;
	opr specifier[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL} };

	if (format == NULL || string_compare(format, "%") == 0)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i]; i++, count++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else
		{
			for (j = 0; specifier[j].spec_char != '\0'; j++)
			{
				if (format[i + 1] == specifier[j].spec_char)
				{
					count += specifier[j].f(ap);
					i++;
					break;
				}
				if (specifier[j + 1].spec_char == '\0')
				{
					print_perc();
					if (format[i + 1] == '%')
						i++;
				}

			}
		}
	}
	va_end(ap);
	return (count);
}
