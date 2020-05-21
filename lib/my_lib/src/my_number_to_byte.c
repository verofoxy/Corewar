/*
** EPITECH PROJECT, 2020
** lib
** File description:
** lib
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *number_to_byte(int number)
{
    char *byte = malloc(sizeof(char) * 8);

    if (byte == NULL)
        return (NULL);
    for (size_t i = 0; i < 8; i++)
        byte[i] = 0;
    for (int i = 0; number != 0; i++) {
        byte[8 - i - 1] = number % 2;
        number /= 2;
    }
    return (byte);
}