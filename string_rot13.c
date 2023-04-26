#include "main.h"
/**
 * rot13 - Applies the ROT13 cipher to a string
 *
 * @s: The string to encrypt
 *
 * Return: len
 */
int rot13(const char *s)
{
	int i, j;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char output[1050];

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			for (j = 0; j < 26; j++)
			{
				if (s[i] == alphabet[j])
				{
					output[i] = alphabet[(j + 13) % 26];
					break;
				}
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			for (j = 0; j < 26; j++)
			{
				if (s[i] == upper[j])
				{
					output[i] = upper[(j + 13) % 26];
					break;
				}
			}
		}
		else
		{
			output[i] = s[i];
		}
	}
	output[i] = '\0';
	return (_puts(output));
}
