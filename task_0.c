#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line
 * @str: pointer to the string to print
 * Return: number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	char *str;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				count += _putchar(va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				count += _puts(str);
				break;
			case '%':
				count += _putchar('%');
				break;
			case '\0':
				return (-1);
			default:
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
