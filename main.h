#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct print - struct for printing
 * @type: type of argument
 * @f: function to print
 */
typedef struct print
{
	char *type;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int _puts(char *str);
int _putchar(char c);

#endif
