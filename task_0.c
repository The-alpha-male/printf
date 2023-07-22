#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - printf function
 * @format: character string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0; /* number of characters printed */
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
	putchar(character_arg);
	count++;
	break;
	case 's':
	str_arg = va_arg(args, char *);
	while (*str_arg)
	{
		putchar(*str_arg);
		str_arg++;
		count++;
	}
	break;
	case '%':
	putchar('%');
	count++;
	break;
	default: /* unsupported identifiers */
	putchar('%');
	putchar(*format);
	count += 2;
	break;
		}
	}
else
{
	putchar(*format);
	count++;
}
format++;
}
va_end(args);
	return (count);
}
