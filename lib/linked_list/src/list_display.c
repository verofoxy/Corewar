/*
** EPITECH PROJECT, 2020
** list_display.c
** File description:
** list_display.c
*/

#include "linked_list.h"

int display_tag(linked_list_t *list)
{
    CHECK_NULL(list)
    for (node_t *n = list->head; n; n = n->next) {
        print("[%s]\n", n->tag);
    }
}