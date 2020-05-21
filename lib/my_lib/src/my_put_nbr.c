/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** convert int en char
*/

#include "my.h"

int print_min_int(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return (0);
}

void my_put_nbr(long long int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }

    if (nb == -2147483648)
        print_min_int();

    if ( nb > 9 ) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb >= 0 && nb <= 9) {
        nb = nb + 48;
        my_putchar(nb);
    }
}