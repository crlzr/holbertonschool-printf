#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to format.
 * @format: Pointer to the format string.
 *
 * Return: Number of characters printed (excluding null terminator).
 */
int _printf(const char *format, ...)
{
	int i; /* Loop counter */
	va_list list;

	format_t get_opt[] = {
		{"c", set_char},
		{"s", set_string},
		{"%", set_percent},
		{"d", set_intone},
		{"i", set_inttwo},
		{NULL, NULL}
	};

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	i = formatspec(format, get_opt, list); /* Using formatspec */

	va_end(list);
	return (i);
}
