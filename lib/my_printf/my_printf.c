/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** exercise tech
*/
#include <stdarg.h>
#include "include/table_pointer_on_function.h"

void my_putchar(char c);

void my_put_nbr(long long int nbr);

void my_printf_S(char *str);

int after_htag(int index, char const *str)
{
    if (str[index] == 'x')
        my_putchar('x');
    else if (str[index] == 'X')
        my_putchar( 'X');
    return (0);
}

int detect_error(va_list list, int index, char *str)
{
    int i;

    if (str[index] == '%') {
        my_putchar(str[index]);
        return (0);
    }
    for (i = 0; letter[i] != str[index] && letter[i] != '0'; i++);
    if (letter[i] != '0') {
        if (letter[i] == '#') {
            my_putchar('0');
            index++;
            after_htag(index, str);
            detect_error(list, index, str);
        }else
            my_mult_printf[i](list);
    }else {
        my_putchar(str[index]);
    }
    return (0);
}

void my_printf(char *str, ...)
{
    int index;
    va_list list_arg;

    va_start(list_arg, str);
    for (index = 0; str[index] != '\0'; index++) {
        if (str[index] == '%') {
            index++;
            if (str[index] == 'l' && str[index - 1] == '%') {
                my_put_nbr(va_arg(list_arg, long long int));
                return;
            }
            detect_error(list_arg, index, str);
        }
        else if (str[index - 1] != '#'){
            my_putchar(str[index]);
        }
    }
    va_end(list_arg);
}