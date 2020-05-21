/*
** EPITECH PROJECT, 2019
** tableaux pointeur sur fonction
** File description:
** list array
*/
#include <stdarg.h>

void my_putnbr(va_list list);

void my_put_str(va_list list);

void my_put_char(va_list list);

void my_printf_octal(va_list list);

void my_printf_binary(va_list list);

void my_printf_address(va_list list);

void my_printf_unsigned(va_list list);

void my_printf_hex_lower(va_list list);

void my_printf_hex_upper(va_list list);

void my_printf_isprintable(va_list list);

char letter[] = {
        's',
        'i',
        'd',
        'c',
        'u',
        'x',
        'o',
        'X',
        'p',
        'b',
        'S',
        '#',
        '0'
};
void (*my_mult_printf[])(va_list) = {
                &my_put_str,
                &my_putnbr,
                &my_putnbr,
                &my_put_char,
                &my_printf_unsigned,
                &my_printf_hex_lower,
                &my_printf_octal,
                &my_printf_hex_upper,
                &my_printf_address,
                &my_printf_binary,
                &my_printf_isprintable
        };