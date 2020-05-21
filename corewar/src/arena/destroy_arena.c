/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void destroy_arena(arena_t *arena)
{
    if (arena->process)
        free(arena->process);
    free(arena);
}