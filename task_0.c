#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_char - Print a single character.
 * @c: The character to print.
 * @count: A pointer to the count of characters printed.
 */
void print_char(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_string - Print a string of characters.
 * @str: The string to print.
 * @count: A pointer to the count of characters printed.
 */
void print_string(const char *str, int *count)
{
	while (*str)
	{
		putchar(*str);
		str++;
		(*count)++;
	}
}

/**
 * _printf - printf function
 * @format: character string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str_arg;
	char character_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					character_arg = va_arg(args, int);
					print_char(character_arg, &count);
					break;
				case 's':
					str_arg = va_arg(args, char *);
					print_string(str_arg, &count);
					break;
				case '%':
					print_char('%', &count);
					break;
				default:
					print_char('%', &count);
					print_char(*format, &count);
					break;
			}
		}
		else
		{
			print_char(*format, &count);
		}
		format++;
	}
	va_end(args);

	return (count);
}
