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

    // Handle negative numbers
    if (n < 0)
    {
        len += _write_char('-');
        num = (unsigned int)(-n); // Convert negative number to unsigned
    }
    else
    {
        num = (unsigned int)n; // Convert positive number to unsigned
    }

    // Calculate the divisor based on the number of digits in num
    while (num / div > 9)
    {
        div *= 10;
    }

    // Print each digit of num
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

    // Calculate the divisor based on the number of digits in num
    while (num / div > 9)
    {
        div *= 10;
    }

    // Print each digit of num
    while (div != 0)
    {
        len += _write_char('0' + num / div);
        num %= div;
        div /= 10;
    }

    return len;
}

