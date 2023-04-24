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
	unsigned int u;

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
	else if (format[(*i) + 1] == 'd' || format[(*i) + 1] == 'i')
		*len += print_number(va_arg(formatPtr, int)) - 1;
	else if (format[(*i) + 1] == 'b')
	{
		u = (va_arg(formatPtr, unsigned int));
		*len += unsigned_to_binary(u) - 1;
	}
	else
	{
		_putchar('%');
		(*i)--;
	}

	(*i)++;
}

/**
 * _printf - prints whatever u like to the stdout
 *
 * @format: the main string that tells u what to print
 * @...: additional arguments
 *
 * Return: length of what was printed
 */
int _printf(const char *format, ...)
{
	va_list formatPtr;
	int i, len = 0;

	va_start(formatPtr, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else
		{
			if (format[i + 1] == 0)
				return (-1);
			print_arg(formatPtr, format, &i, &len);
		}
		len++;
	}
	va_end(formatPtr);
	return (len);
}
