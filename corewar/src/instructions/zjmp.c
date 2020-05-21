/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** zjmp.c
*/

#include <stdio.h>
#include "instruction.h"

void op_zjmp(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];

    if (prog->carry == 1)
        prog->cursor += prog->args[0].value % IDX_MOD;
    else
        prog->cursor += 3;
    if (prog->cursor >= MEM_SIZE)
        prog->cursor = prog->cursor % MEM_SIZE;
}