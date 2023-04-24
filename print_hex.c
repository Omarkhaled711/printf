#include "main.h"

/**
 * print_hex - prints number in hex
 * @num: the unsigned number to print
 *
 * Return: len
 */
int print_hex(unsigned int num)
{
	int len = 0;
	char hex_digits[] = "0123456789abcdef";

	if (num >= 16)
	{
		len += print_hex(num / 16);
	}
	_putchar(hex_digits[num % 16]);
	len++;
	return (len);
}
/**
 * print_HEX - prints number in HEX
 * @num: the unsigned number to print
 *
 * Return: len
 */
int print_HEX(unsigned int num)
{
	int len = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (num >= 16)
	{
		len += print_HEX(num / 16);
	}
	_putchar(hex_digits[num % 16]);
	len++;
	return (len);
}
