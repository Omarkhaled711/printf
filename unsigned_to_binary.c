#include "main.h"
/**
 * unsigned_to_binary -convert unsigned int to binary
 *
 * @num: input
 * Return: int
 *
 */
int unsigned_to_binary(unsigned int num)
{

	char result[sizeof(num) * 8];
	int count = 0, len = 0;

	while (num)
	{
		result[count++] = (((num & 1) == 1) ? '1' : '0');
		num >>= 1;
	}

	if (count)
	{
		count--;
		while (count >= 0)
		{
			_putchar(result[count--]);
			len++;
		}
	}
	else
	{
		_putchar('0');
	}
	return (len);
}
