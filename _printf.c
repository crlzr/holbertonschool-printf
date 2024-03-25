#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to format
 * @format: Pointer to format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int i;

	format_t get_opt[] = {
	{"c", set_char},
	{"s", set_string},
	{"%", set_percent},
	{NULL, NULL}
	};

	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	i = format_spec(format, get_opt, list);

	va_end(list);
	return (i);
}
