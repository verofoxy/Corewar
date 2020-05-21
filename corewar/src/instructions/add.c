/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** add.c
*/

#include "instruction.h"

void op_add(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];

    prog->registers[prog->args[2].position] =
    prog->registers[prog->args[1].position] +
    prog->registers[prog->args[0].position];
    if (prog->registers[prog->args[2].position] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}