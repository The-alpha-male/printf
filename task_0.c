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
int count = 0; /* number of characters */

va_start(args, format);

for (; *format != '\0'; format++)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
count += print_string(va_arg(args, char *));
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
}

va_end(args);
return (count);
}

/**
 * print_char - prints a character
 * @c: character to print
 * Return: number of characters printed
 */
int print_char(int c)
{
putchar(c);
return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
int count = 0;

for (; *s != '\0'; s++)
{
putchar(*s);
count++;
}

return (count);
}
