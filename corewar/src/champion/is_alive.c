/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void is_alive(arena_t *arena)
{
    for (int i = 0; i < arena->nb_player; i++) {
        arena->number[i].last_live++;
        if (arena->number[i].last_live > arena->cycle_to_die) {
            arena->number[i].is_alive = false;
        }
    }
}