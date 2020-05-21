/*
** EPITECH PROJECT, 2020
** check_arg.c
** File description:
** check_arg.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "linked_list.h"
#include "parser.h"

bool check_labels(char *str, linked_list_t *list)
{
    for (node_t *n = list->head; n; n = n->next)
        if (m_strcmp(n->tag, split(str, ',')[0]) == 0)
            return true;
    print("label non trouver\n");
    return false;
}

bool check_direct(char *str, linked_list_t *list)
{

    return str[0] == DIRECT_CHAR;
}

bool check_register(char *str)
{
    return str[0] == 'r';
}

bool check_indirect(char *str, struct linked_list_s *list)
{
    char *st = LABEL_CHARS;
    bool find = false;

    if (str[0] >= 48 && str[0] <= 57)
            return true;
    if (str[0] == LABEL_CHAR)
            return true;
    return false;
    /*for (int i = 0; str[i]; i++) {
        for (int j = 0; st[j]; j++) {
            if (str[i] == st[j])
                find = true;
        }
        if (!find)
            return false;
    }
    return true;*/
}