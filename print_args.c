#include "main.h"
/**
 * print_arg - handles the else part of the _printf function
 *
 * @formatPtr: pointer to the argument list
 * @format: the main string that tells u what to print
 * @i: the index of the current format specifier
 * @len: pointer to the length of what was printed
 *
 * Return: void
 */
void print_arg(va_list formatPtr, const char *format, int *i, int *len)
{
	char *str;
	int flag;

	if (format[(*i) + 1] == 'c')
		_putchar(va_arg(formatPtr, int));
	else if (format[(*i) + 1] == 's')
	{
		str = va_arg(formatPtr, char *);
		if (str == NULL)
			str = "(null)";
		*len += _puts(str) - 1;
	}
	else if (format[(*i) + 1] == '%')
		_putchar('%');
	else if (format[(*i) + 1] == 'd' || format[(*i) + 1] == 'i' || check_int_flags(format[(*i) + 1], format[(*i) + 2]))
	{
		flag = check_int_flags(format[(*i) + 1], format[(*i) + 2]);
		*len += print_number(va_arg(formatPtr, int), flag) - 1;
		if (flag != 0)
			(*i)++;
	}
	else if (format[(*i) + 1] == 'b')
		*len += unsigned_to_binary(va_arg(formatPtr, unsigned int)) - 1;
	else if (format[(*i) + 1] == 'u')
		*len += print_unsignedNum(va_arg(formatPtr, unsigned int)) - 1;
	else if (format[(*i) + 1] == 'o' || (format[(*i) + 2] == 'o' && check_unsignedFlags(format[(*i) + 1], format[(*i) + 2])))
	{
		flag = check_unsignedFlags(format[(*i) + 1], format[(*i) + 2]);
		*len += print_octal(va_arg(formatPtr, unsigned int), flag) - 1;
		if (flag != 0)
			(*i)++;
	}
	else if (format[(*i) + 1] == 'x' || (format[(*i) + 2] == 'x' && check_unsignedFlags(format[(*i) + 1], format[(*i) + 2])))
	{
		flag = check_unsignedFlags(format[(*i) + 1], format[(*i) + 2]);
		*len += print_hex(va_arg(formatPtr, unsigned int), flag) - 1;
		if (flag != 0)
			(*i)++;
	}
	else if (format[(*i) + 1] == 'X' || (format[(*i) + 2] == 'X' && check_unsignedFlags(format[(*i) + 1], format[(*i) + 2])))	
	{
		flag = check_unsignedFlags(format[(*i) + 1], format[(*i) + 2]);
		*len += print_HEX(va_arg(formatPtr, unsigned int), flag) - 1;
		if (flag != 0)
			(*i)++;
	}
	else if (format[(*i) + 1] == 'S')
	{
		str = va_arg(formatPtr, char *);
		if (str == NULL)
			str = "(null)";
		*len += puts_with_HEX(str) - 1;
	}
	else
	{
		_putchar('%');
		(*i)--;
	}

	(*i)++;
}

