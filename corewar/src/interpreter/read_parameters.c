/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"
#include "struct.h"

int read_parameter(int size, int start_position, arena_t *arena)
{
    int result = 0;

    for (int i = size - 1; i != -1; i--) {
        result += arena->cases[start_position].value;
        if (i == size - 1 && result == 255)
            result = -256;
        start_position++;
    }
    return (result);
}