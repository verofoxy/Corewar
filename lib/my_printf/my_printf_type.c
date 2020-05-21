/*
** EPITECH PROJECT, 2019
** my_printf_type
** File description:
** printf all types
*/

#include <stdarg.h>

void my_putchar(char c);

void my_putstr(char *str);

void my_put_nbr(long long int nb);

void my_put_nbr_unsigned(unsigned int nb);

void my_printf_S(char *str);

void my_put_char(va_list list)
{
    my_putchar((char) va_arg(list, int));
}

void my_putnbr(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void my_put_str(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void my_printf_unsigned(va_list list)
{
    my_put_nbr_unsigned(va_arg(list, unsigned int));
}

void my_printf_isprintable(va_list list)
{
    my_printf_S(va_arg(list, char *));
}
