/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "op.h"
#include "instruction.h"

void op_ldi(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int sum = 0;
    int result = 0;
    int value_1 = prog->args[0].type == REGISTER ?
    prog->registers[prog->args[0].position] : prog->args[0].value % IDX_MOD;
    int value_2 = prog->args[1].type == REGISTER ?
    prog->registers[prog->args[1].position] : prog->args[1].value % IDX_MOD;

    sum = read_parameter(IND_SIZE, prog->pc + value_1, arena);
    sum += value_2;
    prog->carry = sum == 0 ? 1 : prog->carry;
    result = read_parameter(REG_SIZE, prog->pc + sum % IDX_MOD, arena);
    prog->registers[prog->args[2].position] = result;
}