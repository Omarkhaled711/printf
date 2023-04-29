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
			case '.':
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
			case '*':
				*flags |= 1 << 7;
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
 * @formatPtr: pointer to the argument list
 * @flags: flags to check
 * Return: None
 */
void extract_width(const char *format, int *i, int *width,
					va_list formatPtr, int flags)
{
	if ((flags >> 7) & 1)
	{
		*width = va_arg(formatPtr, int);
	}
	else if (is_digit(format[*i + 1]))
	{
		*width = _atoi(format + *i);
		while (is_digit(format[*i + 1]))
			(*i)++;
	}
}

/**
 * check_precision - checks the precision from a format string
 *
 * @width: The width (the precision)
 * @flags: the flags
 * Return: None
 */
void check_precision(int *width, int *flags)
{
	if (((*flags >> 0) & 1) && *width > 0)
	{
		*flags |= 1 << 4;

		if ((*flags >> 1) & 1)
		{
			*width += 1;
		}
		if ((*flags >> 2) & 1)
		{
			*width += 1;
		}
	}
}
