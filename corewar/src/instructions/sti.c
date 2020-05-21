/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void op_sti(arena_t *arena, int process)
{
    int adress = 0;
    sys_t *prog = &arena->process[process];

    adress = prog->args[1].type == REGISTER ?
    prog->registers[prog->args[1].position] : prog->args[1].value % IDX_MOD;
    adress += prog->args[2].type == REGISTER ?
    prog->registers[prog->args[2].position] : prog->args[2].value % IDX_MOD;
    adress = adress % IDX_MOD;
    write_byte(arena, prog->registers[prog->args[0].position],
    (prog->pc + adress) % MEM_SIZE, REG_SIZE);
}