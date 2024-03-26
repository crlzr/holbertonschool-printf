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

	format_t get_opt[] = {
	{"c", set_char},
	{"s", set_string},
	{"%", set_percent},
	{NULL, NULL}
	};
	
	int i;
	int j;
	int ret;
	int count = 0;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

        /* Loop through each character of format string */
        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {       /* Loop through format_t array */
                        for (j = 0; get_opt[j].string != NULL; j++)
                        {       /* i + 1 = specifier, check if it matches symbol */
                                if (format[i + 1] == get_opt[j].string[0])
                                {       /* calls function pointed to by f*/
                                        ret = get_opt[j].f(list);
                                        if (ret == -1)
                                                return (-1);
                                        count += ret;
                                        break;
                                }
                        }
                        if (get_opt[j].string == NULL && format[i + 1] != ' ')
                        {
                                if (format[i + 1] != '\0')
                                {
                                        _write_char(format[i]);
                                        _write_char(format[i + 1]);
                                        count += 2;
                                }
                                else
                                        return (-1);
                        }
                        i++;
                }
                else
                {
                        _write_char(format[i]);
                        count++;
                }
        }
	va_end(list);
        return (count);
}

