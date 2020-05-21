/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** xor.c
*/

#include "instruction.h"

void op_xor(arena_t *arena, int process)
{
    int value = 0;
    sys_t *prog = &arena->process[process];

    if (prog->args[0].type == REGISTER)
        value = prog->registers[prog->args[0].position];
    else
        value = prog->args[0].value;
    if (prog->args[1].type == REGISTER)
        value ^= prog->registers[prog->args[1].position];
    else
        value ^= prog->args[1].value;
    prog->registers[prog->args[2].position] = value;
    if (value == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}