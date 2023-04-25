#include "main.h"

/**
 * print_unsignedNum - print unsigned number
 *
 * @num: the unsigned number
 * @flag: check flags
 * Return: len
 */
int print_unsignedNum(unsigned long num, int flag)
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
	flag = 0;
	if (num >= 10)
	{
		len += print_unsignedNum(num / 10, flag);
	}
	_putchar('0' + (num % 10));
	len++;
	return (len);
}
