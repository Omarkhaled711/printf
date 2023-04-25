#include "main.h"
/**
 * string_reverse - reverses a string
 *
 * @str: the string to reverse
 * Return: void
 */
int string_reverse(char *str)
{
	int len, i;
	char str2[1500];

	for (len = 0; str[len]; len++)
	{
	}
	for (i = 0; i < len; i++)
	{
		str2[i] = str[len -  i - 1];
	}
	str2[len] = 0;
	_puts(str2);
	return (len);
}
