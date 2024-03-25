#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to format
 * @format: Pointer to format string
 * Return: Number of characters printed
 */

/**
 * set_char - print a character
 * @list: list of characters
 * Return: Will return the amount of characters printed
 */

int set_char(va_list list)
{
        _write_char(va_arg(list, int));
        return (1);
}

/**
 * set_string - print a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed
 */
int set_string(va_list list)
{
        int index;
        char *string;

        string = va_arg(list, char *);
        if (string == NULL)
                string = "(null)";
        for (index = 0; string[index] != '\0'; index++)
                _write_char(string[index]);
        return (index);
}

/**
 * set_percent - print a percentage
 * @list: list of arguments
 * Return: Will return the number of characters printed
 */

int set_percent(va_list list __attribute__((unused)))
{
        _write_char('%');
        return (1);
}

int _printf(const char *format, ...)
{
	int i = 0;
	va_list list;

	format_t get_opt[] = {
	{"c", set_char},
	{"s", set_string},
	{"%", set_percent},
	{NULL, NULL}
	};

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	i = format_spec(format, get_opt, list);

	va_end(list);

	return (i);
}
