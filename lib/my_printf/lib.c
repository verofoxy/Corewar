/*
** EPITECH PROJECT, 2019
** all function for my lib
** File description:
** lib.c
*/

void my_putchar(char c);

void my_putstr(char *str);

void my_put_nbr_unsigned(unsigned int nb)
{
    if ( nb > 9 ) {
        my_put_nbr_unsigned(nb / 10);
        my_put_nbr_unsigned(nb % 10);
    }
    if (nb >= 0 && nb <= 9) {
        nb = nb + 48;
        my_putchar(nb);
    }
}