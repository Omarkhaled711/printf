#include "main.h"

/**
 * deal_width - dealing with width field
 *
 * @len: length
 * @width: width
 * Return: len of padding or 0
 */
int deal_width(int len, int width)
{
	int i;

	if (len > width)
		return (0);
	for (i = 0; i < (width - len); i++)
		_putchar(' ');
	return (i);
}
