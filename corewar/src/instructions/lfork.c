/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void op_lfork(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int adress = (prog->pc + prog->args[0].value) % MEM_SIZE;
    sys_t *child = create_system(prog->filename, prog->number);

    if (!child)
        exit(84);
    arena->process = add_process(arena, adress, *child);
}