/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void get_champion_name(sys_t *sys)
{
    node_t *tmp = sys->code->head;
    bytes_t *park = tmp->element;

    for (int i = 0; i < 4; i++)
        tmp = tmp->next;
    for (int i = 0; i < PROG_NAME_LENGTH; i++) {
        park = tmp->element;
        sys->name[i] = park->value;
        tmp = tmp->next;
        park = tmp->element;
    }
}