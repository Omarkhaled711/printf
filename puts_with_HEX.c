#include "main.h"

/**
 * puts_with_HEX - Non printable characters, are printed this way:
 * \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 *
 * @str: string
 * Return: len
 */
int puts_with_HEX(char *str)
{
	int i, len = 0;

	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if ((str[i] / 16) < 10)
			{
				_putchar((str[i] / 16) + '0');
			}
			else
			{
				_putchar((str[i] / 16) - 10 + 'A');
			}
			if ((str[i] % 16) < 10)
			{
				_putchar((str[i] % 16) + '0');
			}
			else
			{
				_putchar((str[i] % 16) - 10 + 'A');
			}
			len += 4;
		}
		else
		{
			_putchar(str[i]);
			len++;
		}
	}
	return (len);
}
