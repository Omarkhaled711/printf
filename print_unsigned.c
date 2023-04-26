#include "main.h"

/**
 * count_undigits - Counts the number of digits in a long number
 *
 * @num: The long number to count digits in
 *
 * Return: The number of digits in the long number
 */
int count_undigits(unsigned long num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
/**
 * print_unsignedNum - print unsigned number
 *
 * @num: the unsigned number
 * @flag: check flags
 * @width: width field
 * Return: len
 */
int print_unsignedNum(unsigned long num, int flag, int width)
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
		len += deal_width(count_undigits(num), width);
	width = 0;

	flag = 0;
	if (num >= 10)
	{
		len += print_unsignedNum(num / 10, flag, width);
	}
	_putchar('0' + (num % 10));
	len++;
	return (len);
}
