#include "main.h"

/**
 * print_hex - prints number in hex
 * @num: the unsigned number to print
 * @flag: checks for # flag
 * Return: len
 */
int print_hex(unsigned long num, int flag)
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

	if (((flag >> 3) & 1) && num > 0)
	{
		_putchar('0');
		_putchar('x');
		len += 2;
	}
	flag = 0;
	if (num >= 16)
	{
		len += print_hex(num / 16, flag);
	}
	_putchar(hex_digits[num % 16]);
	len++;
	return (len);
}
/**
 * print_HEX - prints number in HEX
 * @num: the unsigned number to print
 * @flag: checks for #flag
 * Return: len
 */
int print_HEX(unsigned long num, int flag)
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

	if (((flag >> 3) & 1) && num > 0)
	{
		_putchar('0');
		_putchar('X');
		len += 2;
	}

	flag = 0;
	if (num >= 16)
	{
		len += print_HEX(num / 16, flag);
	}
	_putchar(hex_digits[num % 16]);
	len++;
	return (len);
}
