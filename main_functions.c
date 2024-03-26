#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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

int set_intone(va_list list)
{
	return (0);
}

int set_inttwo (va_list list)
{
	return (0);
}
