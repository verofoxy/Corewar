/*
** EPITECH PROJECT, 2020
** lib
** File description:
** lib
*/

#include "my.h"

char *my_revstr(char *src)
{
    int size = my_strlen(src);
    char temp = 0;

    for (int i = 0; i < size / 2; i++) {
        temp = src[size - i - 1];
        src[size - i - 1] = src[i];
        src[i] = temp;
    }
    return (src);
}