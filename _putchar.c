#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - writes the character c to stdout
 *
 * @c: the char to print
 * @width: checks the width field
 * Return: int
 */
int print_char(char c, int width)
{
	int len = 0, flag = 0;

	if (width > 0)
	{
		len += deal_width(1, width, &flag);
		width = 0;
	}
	len += _putchar(c);
	if (width < 0)
		len += deal_width(1, -width, &flag);
	return (len);
}

