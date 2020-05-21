/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"
#include "linked_list.h"

void op_aff(arena_t *arena, int process)
{
    sys_t *prog = &arena->process[process];
    int output = prog->registers[prog->args[0].position];

    for (; output < 0; output += 256);
    for (; output > 127; output -= 256);
    my_printf("%c", output);
}