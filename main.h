#ifndef HEADER_FILE
#define HEADER_FILE

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int set_char(va_list list);
int set_string(va_list list);
int set_percent(va_list list);
int _write_char(char c);
int _putchar(char c);

/**
 * struct conversion - template for a structure
 * @string: the operator
 * @f: pointer to a function
 */

typedef struct conversion
{
	char *string;
	int (*f)(va_list);

} format_t;

int format_spec(const char *format, format_t get_opt[], va_list list);
#endif
