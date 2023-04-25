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

	if (flag != 0 && n >= 0)
	{
		_putchar(flag);
		len++;
	}
	flag = 0;
	if (n < 0)
	{
		_putchar('-');
		n = -n;
		len++;
	}
	if (n / 10)
	{
		len += print_number(n / 10, flag);
	}

	_putchar((n % 10) + '0');
	len++;
	return (len);
}
