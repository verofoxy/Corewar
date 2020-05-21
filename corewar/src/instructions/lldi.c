/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void op_lldi(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int sum = 0;
    int result = 0;
    int value_1 = prog->args[0].type == REGISTER ?
    prog->registers[prog->args[0].position] : prog->args[0].value;
    int value_2 = prog->args[1].type == REGISTER ?
    prog->registers[prog->args[1].position] : prog->args[1].value;

    sum = read_parameter(IND_SIZE, prog->pc + value_1 , arena);
    sum += value_2;
    prog->carry = sum == 0 ? 1 : prog->carry;
    result = read_parameter(REG_SIZE, prog->pc + sum, arena);
    prog->registers[prog->args[2].position] = result;
}