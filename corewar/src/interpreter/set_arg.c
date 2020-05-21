/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "prototype.h"

void set_coding_arg(linked_list_t *code)
{
    node_t *tmp = code->head;
    bytes_t *park;

    while (tmp) {
        park = tmp->element;
        if (park->type == INSTRUCTION && (park->value == 1 ||
        park->value == 9 || park->value == 12 || park->value == 15)) {
            tmp = tmp->next;
            tmp = park->value == 1 ? set_bench_type(DIRECT, 4, tmp) :
            set_bench_type(INDEX, 2, tmp);
            continue;
        }
        tmp = tmp->next;
    }
}