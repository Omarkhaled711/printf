#include "main.h"

/**
 * print_octal - prints an unsigned number in octal
 *
 * @num: the unsigned number
 * @flag: checks for '#'
 * Return: length
 */
int print_octal(unsigned int num, int flag)
{
	int len = 0;

	if (flag == '#')
	{
		_putchar('0');
		len++;
	}
	flag = 0;
	if (num >= 8)
	{
		len += print_octal(num / 8, flag);
	}
	_putchar('0' + (num % 8));
	len++;
	return (len);
}
