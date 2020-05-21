/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"
#include "op.h"

void update_cycle(arena_t *arena)
{
    static int current = 0;

    if (current == NBR_LIVE) {
        current = -1;
        arena->cycle_to_die -= CYCLE_DELTA;
    }
    current++;
}