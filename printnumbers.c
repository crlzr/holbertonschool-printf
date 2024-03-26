#include "main.h"

/**
 * print_number - print a number
 * @list: list of numbers
 * Return: The number of characters printed
 */
int print_number(va_list list)
{
    int n = va_arg(list, int);
    int div = 1;
    int len = 0;
    unsigned int num;

    if (n < 0)
    {
        len += _write_char('-');
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    while (num / div > 9)
    {
        div *= 10;
    }

    while (div != 0)
    {
        len += _write_char('0' + num / div);
        num %= div;
        div /= 10;
    }

    return len;
}

/**
 * print_unsigned_number - print an unsigned number
 * @list: list of unsigned numbers
 * Return: The number of characters printed
 */
int print_unsigned_number(unsigned int list)
{
    int len = 0;
    unsigned int num = list;
    unsigned int div = 1;

    while (num / div > 9)
    {
        div *= 10;
    }

    while (div != 0)
    {
        len += _write_char('0' + num / div);
        num %= div;
        div /= 10;
    }

    return len;
}

