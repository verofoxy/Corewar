/*
** EPITECH PROJECT, 2020
** list_destroy.c
** File description:
** list_destroy.c
*/

#include "linked_list.h"
#include <stdlib.h>

int list_destroy(linked_list_t *list)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("la list est vide\n");
        return ERROR;
    }
    for (; n; n = list->head) {
        if (n->next != NULL) n->next->previous = n->previous;
        if (n->previous != NULL) n->previous->next = n->next;
        list->head = n->next;
        free(n);
    }
    return (0);
}