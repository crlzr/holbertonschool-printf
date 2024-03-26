#include <stdarg.h>
#include "main.h"

/**
 * formatspec - Format specification function.
 * @format: The format string.
 * @get_opt: Array of format_t structures.
 * @list: The variable argument list.
 *
 * Return: Number of characters printed (excluding null terminator).
 */
int formatspec(const char *format, format_t get_opt[], va_list list)
{
	int i, j, ret, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; get_opt[j].string != NULL; j++)
			{
				if (format[i + 1] == get_opt[j].string[0])
				{
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

