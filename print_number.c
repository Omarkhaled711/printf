#include "main.h"

/**
 * print_number - prints an integer using _putchar
 *
 * @n: number to be printed
 * @flag: checks for + or space
 * Return: int
 */
int print_number(long n, int flag)
{
	int len = 0;
	long num;

	if ((flag >> 6) & 1)
	{
		n = (short) n;
	}
	else if (!((flag >> 5) & 1))
	{
		n = (int) n;
	}
	num = n;
	if (((flag >> 1) & 1) && n >= 0)
	{
		_putchar('+');
		len++;
	}
	else if (((flag >> 2) & 1) && n >= 0)
	{
		_putchar(' ');
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
 * @flag: checks + or space flags
 */
void print_integer(va_list formatPtr, int *len, int flag)
{
	*len += print_number(va_arg(formatPtr, long), flag) - 1;
}
