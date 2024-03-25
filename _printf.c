#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to format
 * @format: pointer to strings
 * Return: pointer to index
 */
int _printf(const char *format, ...)
{
    int i;      /* loop counter */
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

