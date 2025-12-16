# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C library function `printf`.
The goal of this project is to reproduce the behavior of `printf` for a subset of format specifiers, while gaining a deeper understanding of variadic functions, parsing, and formatted output in C.

This library provides the function:

```c
int ft_printf(const char *format, ...);
```

# Instructions

To compile the library, run:

```bash
make all
```

This will produce the static library libftprintf.a at the root of the repository.

Available Makefile rules:

* `make` / `make all` : Compile the library
* `make clean` : Remove object files
* `make fclean` : Remove object files and the library
* `make re` : Recompile everything from scratch

A main function(commented out) will be written in `ft_printf` source file which can be put into a `main.c` file after make was ran for testing:

```c
 #include <stdio.h>
 #include "ft_printf.h"

 int main(void)
 {
     int a, b;
     char *str = "world";
     int num = 42;
     void *ptr = #

     a = printf("Hello %s %d %u %x %X %p %%\n", str, num, num, num, num, ptr);
     b = ft_printf("Hello %s %d %u %x %X %p %%\n", str, num, num, num, num, ptr);

     printf("printf returned: %d\n", a);
     printf("ft_printf returned: %d\n", b);

     a = printf("NULL pointer: %p\n", NULL);
     b = ft_printf("NULL pointer: %p\n", NULL);
     printf("printf returned: %d\n", a);
     printf("ft_printf returned: %d\n", b);

     return 0;
}
```

Compile with:

```bash
cc main.c libftprintf.a
./a.out
```

# Features

#### Handles the following conversions:

* `%c` : Prints a single character
* `%s` : Prints a string
* `%p` : Prints a pointer address in hexadecimal
* `%d` / `%i` : Prints a signed decimal integer
* `%u` : Prints an unsigned decimal integer
* `%x` : Prints a hexadecimal number (lowercase)
* `%X` : Prints a hexadecimal number (uppercase)
* `%%` : Prints a percent sign

Returns the total number of characters printed, like the original `printf`.

# Algorithm and Data Structure

### Overall Flow

* Iterate through the format string character by character.
* Print normal characters directly.
* When encountering `%`, parse the format specifier.
* Fetch the corresponding argument using `va_list`.
* Call the appropriate helper function to print the value.
* Keep track of the total number of characters printed.

### Parsing

* A simple parser identifies the conversion specifier (`cspdiuxX%`).

### Handling Conversions

Separate helper functions handle each conversion:

* `ft_print_char`, `ft_print_str`, `ft_print_ptr`, `ft_print_int`, `ft_print_uint`, `ft_print_hex`, etc.
* Numbers are converted to strings using custom base conversion functions (e.g., recursive division or iterative loops).

# Resources

### References

* Youtube videos
* C standard library documentation for `printf` and `stdarg.h`

### AI Usage

AI was used for:

* Explaining how the `printf` function ddealt with the specifiers mentioned before to match it as much as possible.
* Structuring and drafting this README template.
* Clarifying documentation and explaining algorithmic choices in plain language.
* Brainstorming how to present the project clearly.

All implementation, debugging, and code logic were done manually.
