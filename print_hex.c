#include "main.h"

/**
 * count_hex_digits - Counts the number of hexadecimal digits in a number
 *
 * @num: The number to count hexadecimal digits in
 *
 * Return: The number of hexadecimal digits in the number
 */
int count_hex_digits(unsigned long num)
{
	int count = 0;

	while (num != 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}
/**
 * print_hex - prints number in hex
 * @num: the unsigned number to print
 * @flag: checks for # flag
 * @width: width field
 * Return: len
 */
int print_hex(unsigned long num, int flag, int width)
{
	int len = 0;
	char hex_digits[] = "0123456789abcdef";

	if ((flag >> 6) & 1)
	{
		num = (unsigned short) num;
	}
	else if (!((flag >> 5) & 1))
	{
		num = (unsigned int) num;
	}
	if (width > 0)
	{
		len += deal_width(count_hex_digits(num), width, &flag);
		width = 0;
	}
	if (((flag >> 3) & 1) && num > 0)
	{
		_putchar('0');
		_putchar('x');
		len += 2;
	}
	flag = 0;
	if (num >= 16)
	{
		len += print_hex(num / 16, flag, width);
	}
	_putchar(hex_digits[num % 16]);
	len++;
	return (len);
}
/**
 * print_HEX - prints number in HEX
 * @num: the unsigned number to print
 * @flag: checks for #flag
 * @width: width field
 * Return: len
 */
int print_HEX(unsigned long num, int flag, int width)
{
	int len = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if ((flag >> 6) & 1)
	{
		num = (unsigned short) num;
	}
	else if (!((flag >> 5) & 1))
	{
		num = (unsigned int) num;
	}
	if (width > 0)
	{
		len += deal_width(count_hex_digits(num), width, &flag);
		width = 0;
	}
	if (((flag >> 3) & 1) && num > 0)
	{
		_putchar('0');
		_putchar('X');
		len += 2;
	}

	flag = 0;
	if (num >= 16)
	{
		len += print_HEX(num / 16, flag, width);
	}
	_putchar(hex_digits[num % 16]);
	len++;
	return (len);
}
