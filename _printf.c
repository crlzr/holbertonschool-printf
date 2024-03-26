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
		{"d", set_intone},
		{"i", set_inttwo},
	};
	
	int i = 0;
	int j = 0;
	char ret;
	int count = 0;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	
	va_start(list, format);
	
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret  = format[i + 1];
			i++;
			
			j = 0;
			while (j < 5)
			{
				 if (*get_opt[j].string == ret)
				{
					 get_opt[j].f(list);
					count++;
				}
				j++;
			}	
		}

		else
		{
			printf("%c", format[i]);
			count++;
		}
		i++;
	}
	va_end(list);
        return (count);
}

