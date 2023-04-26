#include "main.h"
#include <limits.h>

/**
 * count_digits - Counts the number of digits in a long number
 *
 * @num: The long number to count digits in
 *
 * Return: The number of digits in the long number
 */
int count_digits(long num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
/**
 * print_number - prints an integer using _putchar
 *
 * @n: number to be printed
 * @flag: checks for + or space
 * @width: width field
 * Return: int
 */
int print_number(long n, int flag, int width)
{
	int len = 0;
	long num;

	if ((flag >> 6) & 1)
		n = (short) n;
	else if (!((flag >> 5) & 1))
		n = (int) n;
	else if (n == LONG_MIN)
		return (_puts("-9223372036854775808"));
	num = n;
	if (width > 0)
		len += deal_width(count_digits(num), width);
	width = 0;
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
		len += print_number(num / 10, flag, width);
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
 * @width: width field
 */
void print_integer(va_list formatPtr, int *len, int flag, int width)
{
	*len += print_number(va_arg(formatPtr, long), flag, width) - 1;
}
