/*
** EPITECH PROJECT, 2020
** list_get.c
** File description:
** list_get.c
*/

#include "linked_list.h"
#include <stdlib.h>

void *get_element_from_tag(linked_list_t *list, char *tag)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("\\033[5m list is empty\n");
        return NULL;
    }
    for (; n && m_strcmp(n->tag, tag) != 0; n = n->next);
    return n->element;
}

void *get_element_from_index(linked_list_t *list, int index)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("la list est vide");
        return NULL;
    }
    for (int i = 0; n && i != index; n = n->next, i++);
    return (n->element);
}

node_t *get_node_from_tag(linked_list_t *list, char *tag)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("la list est vide");
        return NULL;
    }
    for (; n && n->tag != tag; n = n->next);
    return n;
}

node_t *get_node_from_index(linked_list_t *list, int index)
{
    node_t *n = list->head;

    if (n == NULL) {
        print("la list est vide");
        return NULL;
    }
    for (int i = 0; n && i != index; n = n->next, i++);
    return (n);
}