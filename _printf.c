#include "main.h"

/**
 * _printf - a function that produces output
 *
 * @format: character string composed of zero or more directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, total = 0, c_str = 0;
	va_list pr;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(pr, format);


	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);

		else if (format[i + 1] == '%')
			_putchar('%');

		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(pr, int));
			i++;
		}

		else if (format[i + 1] == 's')
		{
			c_str = put_str(va_arg(pr, char *));
			total += (c_str - 1);
			i++;
		}

		else if (format[i + 1] == ' ')
			return (-1);

		total++;
	}

	va_end(pr);
	return (total);
}

