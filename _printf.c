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
