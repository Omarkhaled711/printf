#include "main.h"

/**
 * print_Address - prints number in hex
 * @ptr: the address print
 * @flag: to write 0x at the front of the address
 * Return: len
 */
int print_Address(void *ptr, int flag)
{
	char hex_digits[] = "0123456789abcdef";
	unsigned long address = (unsigned long)ptr;
	int len = 0;

	if (ptr == NULL)
	{
		return (_puts("(nil)"));
	}

	if (flag != 0)
	{
		_putchar('0');
		_putchar('x');
		len += 2;
	}
	flag = 0;
	if (address >= 16)
	{
		len += print_Address((void *)(address / 16), flag);
	}
	_putchar(hex_digits[address % 16]);
	len++;
	return (len);
}

