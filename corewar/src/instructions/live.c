/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void op_live(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];

    print("The player %d (", prog->args[0]);
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        print("%c", prog->name[i]);
    print(") is alive.\n");
    for (int i = 0; i < arena->nb_player; i++)
        if (arena->number[i].number == prog->number)
            arena->number[i].last_live = 0;
}