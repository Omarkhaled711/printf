#include "main.h"
/**
 * _puts - a function that prints  a string.
 *
 * @str: the string to print
 * Return: str length
 */
int _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
/**
 * print_string - prints a string
 *
 * @formatPtr: pointer to the argument list
 * @len: pointer to the length of what was printed
 */
void print_string(va_list formatPtr, int *len)
{
	char *str = va_arg(formatPtr, char *);

	if (str == NULL)
		str = "(null)";
	*len += _puts(str) - 1;
}
