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


	va_start(pr, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && format[2] == '\0')
		return (-1);

	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			total += _putchar(format[i]);

		else if (format[i] == '%' && format[i] != ' ')
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				total++;
			}
			else if (format[i] == 'c')
			{
				_putchar(va_arg(pr, int));
				total++;
			}
			else if (format[i] == 's')
			{
				c_str = put_str(va_arg(pr, char *));
				total = total + (c_str - 1);
			}
		}
	}
	va_end(pr);
	return (total);
}
