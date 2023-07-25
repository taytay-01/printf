#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move to the next character after '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    printed_chars++;
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        printed_chars++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    printed_chars += 2;
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

int main() {
    _printf("Hello, %s! Today is %c%%s.\n", "John", 'M');
    return 0;
}

