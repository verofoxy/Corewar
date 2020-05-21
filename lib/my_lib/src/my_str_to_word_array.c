/*
** EPITECH PROJECT, 2020
** tyuio
** File description:
** dfghjkl
*/

#include <stdlib.h>
#include "my.h"

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z' || (c >= 'A' && c <= 'Z'))
        return 0;
    return 1;
}

int count_words(char *str, char split)
{
    int floor = 0;

    for (int count = 0; str[count]; count++)
        if (str[count] == split)
            floor++;
    return floor;
}

char **split_instruction(char *str)
{
    char **splits = malloc(sizeof(char *) * 3);
    int i = 0, j = 0;

    for (; str[i] != ' '; i++);
    splits[0] = malloc(sizeof(char) * i);
    for (int p = 0; p != i; p++)
        splits[0][p] = str[p];
    splits[1] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (int k = i + 1; str[k]; k++, j++)
        splits[1][j] = str[k];
    splits[1][j] = 0;
    splits[2] = NULL;
    return splits;
}

char **split(char *order, char sep)
{
    char **parse_order = NULL;
    int nb_arg = 2;
    int start = 0;

    for (int i = 0; order[i]; i++)
        nb_arg = order[i] == sep ? nb_arg + 1 : nb_arg;
    parse_order = malloc(sizeof(char *) * nb_arg);
    for (int i = 0; i < nb_arg - 1; i++)
        parse_order[i] = malloc(sizeof(char) * my_strlen(order) + 1);
    for (int i = 0; i < nb_arg - 1; i++) {
        for (int j = 0; order[start] != sep && order[start]; j++) {
            parse_order[i][j] = order[start];
            parse_order[i][j + 1] = 0;
            start++;
        }
        start++;
    }
    parse_order[nb_arg - 1] = NULL;
    return (parse_order);
}