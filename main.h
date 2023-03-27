#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct opr - defines a structure for operations
 * @spec_char: specifying character
 *
 * @f: function pointer that matches specifier
 *
 */

typedef struct opr
{
	char spec_char;
	int (*f)(va_list ap);
} opr;


/* Prototype function for _putchar */
int _putchar(char c);

/* Prototype function to determine string length */
int string_length(char *s);

/*Prototype function to determine string comparison */
int string_compare(const char *s1, char *s2);

/* Prototype function of main printf to print string and call formatting */
int _printf(const char *format, ...);

/* Prototype function to format printing character */
int print_char(va_list ap);

/* Prototype function to format printing string */
int print_string(va_list ap);

/* Prototype function to format printing integer */
int print_int(va_list ap);

/* Prototype function to format printing string in rot13 */
int print_rot13(va_list ap);

/* Prototype function to format printing string in reverse */
int print_reverse(va_list ap);

/* Prototype function to format printing percent character */
int print_perc(void);

/*Prototype function to format printing binary number */
int print_binary(va_list ap);

/*Prototype function to format printing octal number */
int print_octal(va_list ap);

/*Prototype function to format printing hexadecimal number (lowercase)*/
int print_hexadecimalx(va_list ap);

/*Prototype function to format printing hexadecimal number (uppercase)*/
int print_hexidecimalX(va_list ap);

/*Prototype function to format printing unsigned int */
int print_unsigned(va_list ap);

/*Prototype function to format printing string with only printable char*/
int print_S(va_list ap);

/*Prototype function to print a string as hexadecimal value */
void hexadecimal(unsigned int s);

#endif
