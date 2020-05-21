/*
** EPITECH PROJECT, 2019
** STRCAT
** File description:
** CONCAT 2 STRING
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);
    int len2 = my_strlen(src);
    char *fusion = malloc(sizeof(char) * len + len2 + 2);

    if (fusion == NULL)
        return NULL;
    my_strcpy(fusion, dest);
    for (i = 0; src[i] != 0; i++) {
        fusion[len + i] = src[i];
        fusion[len + i + 1] = 0;
    }
    return fusion;
}
