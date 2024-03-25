#ifndef HEADER_FILE
#define HEADER_FILE

int _printf(const char *format, ...);

/**
 * struct conversion - template for a structure
 * @string: the operator
 * @f: pointer to a function
 */
struct conversion
{
    char *string;
    int(*f)(va_list);

}; typedef struct conversion format_t;

#endif
