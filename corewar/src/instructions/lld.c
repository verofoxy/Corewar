/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void op_lld(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int adress = prog->pc + prog->args[0].value;
    int result = read_parameter(REG_SIZE, adress, arena);

    prog->carry = result == 0 ? 1 : 0;
    prog->registers[prog->args[1].position] = result;
}