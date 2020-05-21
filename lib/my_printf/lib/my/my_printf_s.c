/*
** EPITECH PROJECT, 2019
** my_printf_S
** File description:
** print
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_printf(char *str, ...);
char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', \
'9', 'A', 'B', 'C', 'D', 'E', 'F'};

void *my_convert_dec_to_oct( unsigned int nb, int base, int level)
{
    int converted_number[64], index = 0;

    while (nb != 0) {
        converted_number[index] = nb % base;
        nb = nb / base;
        ++index;
    }
    --index;
    for (; index >= 0; index--) {
        if (level == 1 && 64 < base_digits[converted_number[index]])
            my_putchar(base_digits[converted_number[index]]  + 32);
        else
            my_putchar(base_digits[converted_number[index]]);
    }
    return (0);
}

void *my_convert_dec(unsigned long int nb, unsigned long long int base, int lvl)
{
    int converted_number[64];
    int next_digit, index = 0;

    while (nb != 0) {
        converted_number[index] = nb % base;
        nb = nb / base;
        ++index;
    }
    --index;
    for (; index >= 0; index--) {
        if (lvl == 1 && 64 < base_digits[converted_number[index]])
            my_putchar(base_digits[converted_number[index]] + 32);
        else
            my_putchar(base_digits[converted_number[index]]);
    }
    return (0);
}

void *my_convert_S( unsigned int nb, int base, int level)
{
    int converted_number[64], index = 0, cases, counter = 0;
    int *str = malloc(sizeof(int) + 5);

    while (nb != 0) {
        converted_number[index] = nb % base;
        nb = nb / base;
        ++index;
    }
    --index;
    for (cases = 0; index >= 0; index--, cases++)
        str[cases] = base_digits[converted_number[index]];
    for (cases = 0; str[cases]; cases++)
        counter++;
    for (cases = 1; cases != 4 - counter; cases++)
        my_putchar('0');
    for (; *str; str++) {
        my_putchar((char) *str);
    }
    return (0);
}

void my_printf_S(char *str)
{
    for (int index = 0; str[index] != '\0'; index++) {
        if (31 < str[index])
            my_putchar(str[index]);
        else{
            my_putstr("\\");
            my_convert_S(str[index], 8, 0);
        }
    }
}
