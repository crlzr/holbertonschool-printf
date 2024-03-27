# _PRINTF - MANUAL PAGE

## NAME
_printf - format and print data

## SYNOPSIS
```c
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
``````

## DESCRIPTION
The ```_printf``` function formats and prints data to standard output (stdout) according to the specified format string (```format```). The format string is a text string containing conversion specifiers that indicate how the corresponding arguments should be formatted and displayed.

Conversion specifiers are introduced by the character ```%``` and are followed by a format code that specifies the data type to be formatted. Some common format codes include:

* ```%c```: Formats and prints a single character.
* ```%s```: Formats and prints a string of characters.
* ```%d```: Formats and prints a signed decimal integer.
* ```%i```: Formats and prints a unsigned decimal integer (equivalent to ```%d```).
* ```%i```: Formats and prints a unsigned decimal integer (equivalent to ```%d```).
* ```%%```: Formats and prints a single percent sign (```%```).

## OPTIONS
In addition to the format specifiers, the ```_printf``` function also supports the following options:

* ```-c```: Suppresses the padding of characters with spaces.
* ```-s```: Suppresses the padding of strings with spaces.
* ```-d```, ```-i```: Suppresses the printing of the sign for positive integers.
* ```-%```: Suppresses the printing of the leading zero for octal and hexadecimal numbers.

## RETURN VALUE
This function returns the number of characters written, excluding the terminating null character (```\0```) used to end the string. A negative value is returned if an error occurs.
## ERRORS
Failure of ```_printf``` function can result from:
* Invalid format for the string
* The argument has an incompatible data type.
* Not enough arguments to satisfy the format specifiers in the format string.
## AUTHORS
This man page was written by Hugh Fagan and Carole Zenruffinen.

