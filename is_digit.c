#include "main.h"

/**
 * is_digit - Checks if a character is a digit
 *
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
