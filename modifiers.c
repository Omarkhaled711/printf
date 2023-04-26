#include "main.h"
/**
 * extract_flags - Extracts the flags from a format string
 *
 * @format: The format string to extract flags from
 * @i: A pointer to the current position in the format string
 * @flags: A pointer to an integer to store the extracted flags
 *
 * Return: None
 */
void extract_flags(const char *format, int *i, int *flags)
{
	char done = 0;
	*flags = 0;
	while (!done)
	{
		(*i)++;
		switch (format[*i])
		{
			case '-':
				*flags |= 1 << 0;
				break;
			case '+':
				*flags |= 1 << 1;
				break;
			case ' ':
				*flags |= 1 << 2;
				break;
			case '#':
				*flags |= 1 << 3;
				break;
			case '0':
				*flags |= 1 << 4;
				break;
			case 'l':
				*flags |= 1 << 5;
				break;
			case 'h':
				*flags |= 1 << 6;
				break;
			default:
				done = 1;
				(*i)--;
				break;
		}
	}
}

/**
 * extract_width - Extracts the width from a format string
 *
 * @format: The format string to extract the width from
 * @i: A pointer to the current position in the format string
 * @width: A pointer to an integer to store the extracted width
 *
 * Return: None
 */
void extract_width(const char *format, int *i, int *width)
{
	if (is_digit(format[*i + 1]))
	{
		*width = _atoi(format + *i);
		while (is_digit(format[*i + 1]))
			(*i)++;
	}
}

/**
 * extract_precision - Extracts the precision from a format string
 *
 * @format: The format string to extract the precision from
 * @i: A pointer to the current position in the format string
 * @precision: A pointer to an integer to store the extracted precision
 *
 * Return: None
 */
void extract_precision(const char *format, int *i, int *precision)
{
	if (format[*i + 1] == '.')
	{
		(*i)++;
		if (is_digit(format[*i + 1]))
		{
			*precision = _atoi(format + *i + 1);
			while (is_digit(format[*i + 1]))
				(*i)++;
		}
		else
			*precision = 0;
	}
}
