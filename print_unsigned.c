#include "main.h"

/**
 * print_unsignedNum - print unsigned number
 *
 * @num: the unsigned number
 * Return: len
 */
int print_unsignedNum(unsigned int num)
{
	int len = 0;

	if (num >= 10)
	{
		len += print_unsignedNum(num / 10);
	}
	_putchar('0' + (num % 10));
	len++;
	return (len);
}
