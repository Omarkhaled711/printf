#include "main.h"

/**
 * _atoi - convert number inside a string into int
 *
 * @s: string that contains the number
 * Return: the integer if it exists or 0 otherwise
 */


int _atoi(const char *s)
{
	int neg = 0, i, ans = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if (ans != 0)
			{
				break;
			}
			if (s[i] == '-')
			{
				neg++;
			}
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			ans *= 10;
			ans -= s[i] - '0';
		}
	}
	if (neg % 2 == 0)
	{
		ans = -ans;
	}
	return (ans);
}

