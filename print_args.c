#include "main.h"

/**
 * print_unsign - prints an unsigned integer in various formats
 *
 * @formatPtr: pointer to the argument list
 * @len: pointer to the length of what was printed
 * @spec: specifier
 * @flag: checks # flag
 */
void print_unsign(va_list formatPtr, int *len, char spec, char flag)
{
	unsigned long num = va_arg(formatPtr, long int);

	if (spec == 'b')
		*len += unsigned_to_binary(num);
	else if (spec == 'u')
		*len += print_unsignedNum(num, flag);
	else if (spec == 'o')
	{
		*len += print_octal(num, flag) - 1;
	}
	else if (spec == 'x')
	{
		*len += print_hex(num, flag) - 1;
	}
	else if (spec == 'X')
	{
		*len += print_HEX(num, flag) - 1;
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
	char spe;
	int width = 0, flags = 0;
	char *str;

	extract_flags(format, i, &flags);
	spe = format[(*i) + 1];
	extract_width(format, i, &width);
	if (spe == 'c')
		_putchar(va_arg(formatPtr, int));
	else if (spe == 's')
		print_string(formatPtr, len);
	else if (spe == '%')
		_putchar('%');
	else if (spe == 'd' || spe == 'i')
		print_integer(formatPtr, len, flags);
	else if (spe == 'b' || spe == 'u' || spe == 'o' || spe == 'x' || spe == 'X')
		print_unsign(formatPtr, len, spe, flags);
	else if (spe == 'p')
		(*len) += print_Address(va_arg(formatPtr, void *), 1) - 1;
	else if (spe == 'S' || spe == 'r')
	{
		str = va_arg(formatPtr, char *);
		if (str == NULL)
		{
			spe = 'S';
			str = "(null)";
		}
		if (spe == 'S')
			*len += puts_with_HEX(str) - 1;
		else
			*len += string_reverse(str) - 1;
	}
	else
	{
		_putchar('%');
		(*i)--;
	}
	(*i)++;
}

