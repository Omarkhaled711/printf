#include "main.h"

/**
 * deal_width - dealing with width field
 *
 * @len: length
 * @width: width
 * @flag: checking zero flag
 * Return: len of padding or 0
 */
int deal_width(int len, int width, int *flag)
{
	int i;

	if (len > width)
		return (0);
	if (((*flag >> 1) & 1) && ((*flag >> 4) & 1))
	{
		_putchar('+');
		*flag = *flag & (~(1 << 1));
		return (deal_width(len, width - 1, flag) + 1);
	}
	else if (((*flag >> 2) & 1) && ((*flag >> 4) & 1))
	{
		_putchar(' ');
		*flag = *flag & (~(1 << 2));
		return (deal_width(len, width - 1, flag) + 1);
	}

	for (i = 0; i < (width - len); i++)
		if ((*flag >> 4) & 1)
			_putchar('0');
		else
			_putchar(' ');
	return (i);
}
