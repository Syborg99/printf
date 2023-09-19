#include "main.h"

/**
 * _strlen - a function to print string and count characters
 *
 * @s: passed string
 *
 * Return: number of characters
 */
int _strlen(char *s)
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
