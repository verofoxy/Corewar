/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"
#include "struct.h"

bool has_codingbyte(int instruction)
{
    int tab[] = {LIVE, ZJMP, FORK, LFORK};

    for (int i = 0; i < 4; i++)
        if (tab[i] == instruction)
            return false;
    return true;
}

bool champ_is_alive(arena_t *arena, int number)
{
    int position = 0;

    for (; arena->number[position].number != number; position++);
    return (arena->number[position].is_alive ? true : false);
}

bytes_t set_args(arena_t *arena, int process, int *cursor)
{
    bytes_t result;
    bytes_t param = arena->cases[*cursor];

    result.type = param.type;
    if (param.type == REGISTER)
        result.position = param.value - 1;
    if (param.type == DIRECT || param.type == INDEX)
        result.value = read_parameter(sizes[param.type], *cursor, arena);
    if (param.type == INDIRECT) {
        result.position = read_parameter(sizes[param.type], *cursor, arena)
        + arena->process[process].pc;
        result.value = get_byte_from_pos(arena, result.position)->value;
    }
    *cursor += sizes[param.type];
    return (result);
}

void wait_order(arena_t *arena, int process)
{
    void (*new_instruction)() = NULL;

    if (arena->process[process].waiting == 0) {
        if (arena->process[process].current_act != 0) {
            new_instruction =
            get_instruction(arena->process[process].current_act);
            new_instruction(arena, process);
            arena->process[process].pc = arena->process[process].cursor;
            arena->process[process].current_act = 0;
        }
        read_instruction(arena, process);
    } else
        arena->process[process].waiting--;
}

bool read_instruction(arena_t *arena, int process)
{
    bytes_t *instruction = get_byte_from_pos(arena, arena->process[process].pc);
    int cursor = arena->process[process].pc % MEM_SIZE;
    sys_t *prog = &arena->process[process];

    if (!champ_is_alive(arena, prog->number) || !instruction ||
    instruction->value == 0)
        return (false);
    cursor += has_codingbyte(instruction->value) ? 2 : 1;
    for (int i = 0; i < ALL_INSTRUCTIONS[instruction->value - 1].nb_arg; i++)
        prog->args[i] = set_args(arena, process, &cursor);
    prog->current_act = instruction->value;
    prog->waiting = ALL_INSTRUCTIONS[instruction->value - 1].cycle;
    prog->cursor = (instruction->value != ZJMP ? cursor : prog->pc) %
    MEM_SIZE;
    return (true);
}