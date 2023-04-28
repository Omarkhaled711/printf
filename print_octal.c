#include "main.h"

/**
 * count_oct_digits - Counts the number of hexadecimal digits in a number
 *
 * @num: The number to count hexadecimal digits in
 *
 * Return: The number of hexadecimal digits in the number
 */
int count_oct_digits(unsigned long num)
{
	int count = 0;

	while (num != 0)
	{
		count++;
		num /= 8;
	}
	return (count);
}

/**
 * print_octal - prints an unsigned number in octal
 *
 * @num: the unsigned number
 * @flag: checks for '#'
 * @width: width field
 * Return: length
 */
int print_octal(unsigned long num, int flag, int width)
{
	int len = 0;

	if ((flag >> 6) & 1)
	{
		num = (unsigned short) num;
	}
	else if (!((flag >> 5) & 1))
	{
		num = (unsigned int) num;
	}
	if (width > 0)
		len += deal_width(count_oct_digits(num), width, &flag);
	width = 0;
	if (((flag >> 3) & 1) && num > 0)
	{
		_putchar('0');
		len++;
	}
	flag = 0;
	if (num >= 8)
	{
		len += print_octal(num / 8, flag, width);
	}
	_putchar('0' + (num % 8));
	len++;
	return (len);
}
