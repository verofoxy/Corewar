/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** st.c
*/

#include "instruction.h"

void op_st(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int adress = 0;

    if (prog->args[1].type == REGISTER)
        prog->registers[prog->args[1].position] =
        prog->registers[prog->args[0].position];
    else {
        adress = prog->pc + prog->args[1].value % IDX_MOD;
        write_byte(arena, prog->registers[prog->args[0].position],
        adress % MEM_SIZE, REG_SIZE);
    }
}