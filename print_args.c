#include "main.h"

/**
 * print_unsign - prints an unsigned integer in various formats
 *
 * @formatPtr: pointer to the argument list
 * @len: pointer to the length of what was printed
 * @spec: specifier
 * @flag: checks flag
 * @width: width field
 */
void print_unsign(va_list formatPtr, int *len, char spec, int flag, int width)
{
	unsigned long num = va_arg(formatPtr, unsigned long);

	if (spec == 'b')
		*len += unsigned_to_binary(num) - 1;
	else if (spec == 'u')
	{
		*len += print_unsignedNum(num, flag, width) - 1;
		if (width < 0)
			*len += deal_width(count_undigits(num), -width, &flag);
	}
	else if (spec == 'o')
	{
		*len += print_octal(num, flag, width) - 1;
		if (width < 0)
			*len += deal_width(count_oct_digits(num), -width, &flag);
	}
	else if (spec == 'x')
	{
		*len += print_hex(num, flag, width) - 1;
		if (width < 0)
			*len += deal_width(count_hex_digits(num), -width, &flag);
	}

	else if (spec == 'X')
	{
		*len += print_HEX(num, flag, width) - 1;
		if (width < 0)
			*len += deal_width(count_hex_digits(num), -width, &flag);
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
	int spe, width = 0, flags = 0;
	char *str;

	extract_flags(format, i, &flags);
	extract_width(format, i, &width, formatPtr, flags);
	check_precision(&width, &flags);
	spe = format[(*i) + 1];
	if (spe == 'c')
		(*len) += print_char(va_arg(formatPtr, int), width) - 1;
	else if (spe == 's')
		print_string(formatPtr, len, width);
	else if (spe == '%')
		_putchar('%');
	else if (spe == 'd' || spe == 'i')
		print_integer(formatPtr, len, flags, width);
	else if (spe == 'b' || spe == 'u' || spe == 'o' || spe == 'x' || spe == 'X')
		print_unsign(formatPtr, len, spe, flags, width);
	else if (spe == 'p')
		(*len) += print_Address(va_arg(formatPtr, void *), 1) - 1;
	else if (spe == 'S' || spe == 'r' || spe == 'R')
	{
		str = va_arg(formatPtr, char *);
		if (str == NULL)
		{
			spe = 'S';
			str = "(null)";
		}
		if (spe == 'S')
			*len += puts_with_HEX(str) - 1;
		else if (spe == 'r')
			*len += string_reverse(str) - 1;
		else if (spe == 'R')
			*len += rot13(str) - 1;
	}
	else
	{
		_putchar('%');
		(*i)--;
	}
	(*i)++;
}

