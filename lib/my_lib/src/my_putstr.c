/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** afficher une string
*/
#include <stdlib.h>
#include "my.h"

void my_putstr(char const *str)
{
    int letter = 0;
    while (str[letter] != '\0') {
        my_putchar(str[letter]);
        letter++;
    }
}
