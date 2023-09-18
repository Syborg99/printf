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

	for (; format && format[i] != '\0';)
	{
		if (format[i] == '%' && format[i + 1] != ' ')
		{
			if (format[i + 1] == '%')
			{
				total += _putchar('%');
			}
			else if (format[i + 1] == 'c')
			{
				total += _putchar(va_arg(pr, int));
			}
			else if (format[i + 1] == 's')
			{
				c_str = put_str(va_arg(pr, char *));
				total = total + (c_str - 1);
			}
			i += 2;
		}
		else
		{
			total += _putchar(format[i]);
			i++;
		}
	}
	va_end(pr);
	return (total);
}
