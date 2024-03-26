#ifndef HEADER_FILE
#define HEADER_FILE

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
/**
 * struct conversion - template for a structure
 * @string: the operator
 * @f: pointer to a function
 */

typedef struct conversion
{
	char *string;
	int (*f)(va_list list);

} format_t;
int formatspec(const char *format, format_t get_opt[], va_list list);
int _write_char(char c);
int set_char(va_list list);
int set_string(va_list list);
int set_percent(va_list list);
int set_intone(va_list list);
int set_inttwo(va_list list);
int print_unsigned_number(unsigned int list);
int print_number(va_list list);
#endif
