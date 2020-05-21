/*
** EPITECH PROJECT, 2020
** list_remove.c
** File description:
** list_remove.c
*/

#include "linked_list.h"
#include <stdlib.h>

int destroy_node_from_tag(linked_list_t *list, char *tag)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("la list est vide\n");
        return ERROR;
    }
    for (; n && n->tag != tag; n = n->next);
    if (n->next != NULL)
        n->next->previous = n->previous;
    if (n->previous != NULL)
        n->previous->next = n->next;
    free(n);
    return (0);
}

int destroy_node_from_index(linked_list_t *list, int index)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("la list est vide\n");
        return ERROR;
    }
    for (int i = 0; n && i != index; n = n->next, i++);
    if (n->next != NULL)
        n->next->previous = n->previous;
    if (n->previous != NULL)
        n->previous->next = n->next;
    free(n);
    return (0);
}