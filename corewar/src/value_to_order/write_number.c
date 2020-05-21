/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

void write_byte(arena_t *arena, int value, int pos, int size)
{
    int writter = pos + size - 1;

    for (int i = pos; i != pos + size; i++)
        arena->cases[i].value = 0;
    if (value >= 0) {
        for (; writter != pos - 1 && writter > 0; writter--) {
            arena->cases[writter].value = value <= 255 ? value : 255;
            value -= arena->cases[writter].value;
        }
    } else {
        arena->cases[pos].value = 255;
        write_byte(arena, 256 - value, pos + 1, size - 1);
    }
}