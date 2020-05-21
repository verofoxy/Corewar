/*
** EPITECH PROJECT, 2020
** add_node.c
** File description:
** add_node.c
*/

#include "linked_list.h"
#include <stdlib.h>

int add_node(linked_list_t *list, void *element, char *tag)
{
    node_t *n = malloc(sizeof(node_t));

    if (!n)
        return (84);
    n->next = NULL;
    n->tag = tag;
    n->previous = NULL;
    n->element = element;
    if (list->head == NULL) {
        list->head = n;
    } else {
        n->previous = list->tail;
        list->tail->next = n;
    }
    list->tail = n;
    return EXEC_SUCCESS;
}

