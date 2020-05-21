/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printf bases
*/
#include <stdarg.h>
#include "include/my.h"

void *my_convert_dec_to_oct(int nb, int base, int level);

void *my_convert_dec(unsigned long long int nb, int base, int level);

void my_printf_hex_lower(va_list list)
{
    my_convert_dec_to_oct(va_arg(list, int), 16, 1);
}

void my_printf_hex_upper(va_list list)
{
    my_convert_dec_to_oct(va_arg(list, int), 16, 0);
}

void my_printf_octal(va_list list)
{
    my_convert_dec_to_oct(va_arg(list, unsigned int), 8, 0);
}

void my_printf_address(va_list list)
{
    my_putstr("0x");
    my_convert_dec(va_arg(list, unsigned long long int), 16, 1);
}

void my_printf_binary(va_list list)
{
    my_convert_dec_to_oct(va_arg(list, int), 2, 0);
}