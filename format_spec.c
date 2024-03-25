#include <stdarg.h>
#include "main.h"

/**
 * format_spec - Format specification function.
 * @format: The format string.
 * @get_opt: Array of format_t structures.
 * @list: The variable argument list.
 * Return: Number of characters printed (excluding null terminator).
 */
int format_spec(const char *format, format_t get_opt[], va_list list)
{
	int i;
	int j;
	int ret;
	int count;
	/* Loop through each character of format string */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{	/* Loop through format_t array */
			for (j = 0; get_opt[j].string != NULL; j++)
			{	/* i + 1 = specifier, check if it matches symbol */
				if (format[i + 1] == get_opt[j].string[0])
				{	/* calls function pointed to by f*/
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
	return (count);
}

