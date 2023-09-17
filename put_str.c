#include "main.h"

/**
 * put_str - a function to print string and count characters
 *
 * @s: passed string
 *
 * Return: number of characters
 */
int put_str(char *s)
{
	int num = 0;

	if (s)
	{
		while (s[num] != '\0')
		{
			_putchar(s[num]);
			num++;
		}
	}

	return (num);
}
