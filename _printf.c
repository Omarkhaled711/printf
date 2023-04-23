#include "main.h"

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
	char *str;

	va_start(formatPtr, format);
	if (format == NULL || (format[0] == '%' && format[1] == 0))
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(formatPtr, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			str = va_arg(formatPtr, char *);
			if (str == NULL)
				str = "(null)";
			len += _puts(str) - 1;
			i++;
		}
		len++;
	}
	va_end(formatPtr);
	return (len);
}
