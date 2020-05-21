/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** ld.c
*/

#include "instruction.h"
#include "op.h"

void op_ld(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int result = prog->args[0].value;

    prog->carry = result == 0 ? 1 : 0;
    prog->registers[prog->args[1].position] = result;
}