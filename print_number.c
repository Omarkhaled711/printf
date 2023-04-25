#include "main.h"

/**
 * print_number - prints an integer using _putchar
 *
 * @n: number to be printed
 * @flag: checks for + or space
 * Return: int
 */
int print_number(int n, int flag)
{
	int len = 0;
	long num = n;

	if (flag != 0 && n >= 0)
	{
		_putchar(flag);
		len++;
	}
	flag = 0;
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		len++;
	}
	if (num / 10)
	{
		len += print_number(num / 10, flag);
	}

	_putchar((num % 10) + '0');
	len++;
	return (len);
}
/**
 * print_integer - prints an integer
 *
 * @formatPtr: pointer to the argument list
 * @len: pointer to the length of what was printed
 * @i: the index of the current format specifier
 * @flag: checks + or space flags
 */
void print_integer(va_list formatPtr, int *len, int *i, char flag)
{
	*len += print_number(va_arg(formatPtr, int), flag) - 1;
	if (flag != 0)
		(*i)++;
}
