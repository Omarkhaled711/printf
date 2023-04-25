#include "main.h"

/**
 * check_int_flags - check + or space flags
 *
 * @flag: checks if char is + or space
 * @spec: checks if specifier is d or i
 * Return: the flag value or 0
 */
int check_int_flags(char flag, char spec)
{
	if ((flag == '+' || flag == ' ') && (spec == 'd' || spec == 'i'))
		return (flag);
	return (0);
}
/**
 * check_unsignedFlags - checks #
 *
 * @flag: checks if char is #
 * @spec: checks if spec is %o || %u || %x || %X
 * Return: the flag value or 0
 */
int check_unsignedFlags(char flag, char spec)
{
	if ((flag == '#') && (spec == 'x' || spec == 'X' || spec == 'o'))
		return (flag);
	return (0);
}
