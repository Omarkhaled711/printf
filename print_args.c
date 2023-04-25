#include "main.h"

/**
 * print_unsign - prints an unsigned integer in various formats
 *
 * @formatPtr: pointer to the argument list
 * @len: pointer to the length of what was printed
 * @spec: specifier
 * @i: the index of the current format specifier
 * @flag: checks # flag
 */
void print_unsign(va_list formatPtr, int *len, char spec, int *i, char flag)
{
	unsigned int num = va_arg(formatPtr, unsigned int);

	if (spec == 'b')
		*len += unsigned_to_binary(num);
	else if (spec == 'u')
		*len += print_unsignedNum(num);
	else if (spec == 'o')
	{
		*len += print_octal(num, flag) - 1;
		if (flag == '#')
			(*i)++;
	}
	else if (spec == 'x')
	{
		*len += print_hex(num, flag) - 1;
		if (flag == '#')
			(*i)++;
	}
	else if (spec == 'X')
	{
		*len += print_HEX(num, flag) - 1;
		if (flag == '#')
			(*i)++;
	}
}
/**
 * print_arg - handles the else part of the _printf function
 *
 * @formatPtr: pointer to the argument list
 * @format: the main string that tells u what to print
 * @i: the index of the current format specifier
 * @len: pointer to the length of what was printed
 */
void print_arg(va_list formatPtr, const char *format, int *i, int *len)
{
	char spe = format[(*i) + 1], second;
	char *str;

	second = spe != 0 ? format[(*i) + 2] : 0;
	if (spe == 'c')
		_putchar(va_arg(formatPtr, int));
	else if (spe == 's')
		print_string(formatPtr, len);
	else if (spe == '%')
		_putchar('%');
	else if (spe == 'd' || spe == 'i')
		print_integer(formatPtr, len, i, 0);
	else if (spe == 'b' || spe == 'u' || spe == 'o' || spe == 'x' || spe == 'X')
		print_unsign(formatPtr, len, spe, i, 0);
	else if ((spe == '+' || spe == ' ') && (second == 'd' || second == 'i'))
		print_integer(formatPtr, len, i, spe);
	else if ((spe == '#') && (second == 'o' || second == 'x' || second == 'X'))
		print_unsign(formatPtr, len, second, i, spe);
	else if (spe == 'S')
	{
		str = va_arg(formatPtr, char *);
		if (str == NULL)
			str = "(null)";
		*len += puts_with_HEX(str);
	}
	else
	{
		_putchar('%');
		(*i)--;
	}
	(*i)++;
}

