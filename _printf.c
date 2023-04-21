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
			else if (format[i + 1] == 'c')
				_putchar(va_arg(formatPtr, int));
			else if (format[i + 1] == 's')
			{
				str = va_arg(formatPtr, char *);
				if (str == NULL)
					str = "(null)";
				len += _puts(str) - 1;
			}
			else if (format[i + 1] == '%')
				_putchar('%');
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				len += print_number(va_arg(formatPtr, int)) - 1;
			else if (format[i + 1] == 'b'){
				unsigned_to_binary(va_arg(formatPtr, unsigned int));
				i++;
			}
			else
			{
				_putchar('%');
				i--;
			}
			i++;
		}
		len++;
	}
	va_end(formatPtr);
	return (len);
}
