/*
** EPITECH PROJECT, 2020
** lib_v2
** File description:
** my_puts
*/

#include "my.h"

void my_putnbrs(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    (nb / 10) ? my_putnbrs(nb / 10) : my_putchar(nb % 10 + '0');
}
