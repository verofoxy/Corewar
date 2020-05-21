/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** list_count.c
*/

#include "linked_list.h"
#include "stdlib.h"

int list_count(linked_list_t *l)
{
    int i = 0;

    if (l != NULL || l->head == NULL)
        return (-1);
    for (node_t *n = l->head; n; n = n->next, i++);
    return i;
}