#include "main.h"
/**
 * string_reverse - reverses a string
 *
 * @str: the string to reverse
 * Return: void
 */
void string_reverse(char *str)
{
	int len, i;
	char temp;

	for (len = 0; str[len]; len++)
	{
	}
	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}
