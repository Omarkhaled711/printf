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
/**
 * print_number - prints an integer using _putchar
 *
 * @n: number to be printed
 * Return: int
 */
int print_number(int n)
{
	char str[18];
	int i = 0, rem, len = 0;
	long num = n;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
	{
		num = num * -1;
	}
	while (num != 0)
	{
		rem = (num % 10) + '0';
		str[i] = rem;
		i++;
		num = num / 10;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = 0;
	string_reverse(str);
	len += _puts(str);
	return (len);
}
