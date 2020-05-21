
/*
** EPITECH PROJECT, 2020
** search.c
** File description:
** search.c
*/

#include "traducteur.h"

bool detect_dont_take_coding_bit(char *st)
{
    bool find = false;

    for (int i = 0; list_not_conding_byte[i] != NULL; i++) {
        if (m_strcmp(st, list_not_conding_byte[i]) == 0) {
            find = true;
            break;
        }
    }
    return find;
}

int pows(int a , int b)
{
    int l = a;

    for (int i = 0; i != b + 1; i++)
        l = l * a;
    return l;
}

int conver_bit_to_dec(ulong n)
{
    int decimalNumber = 0, i = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pows(2, i);
        ++i;
    }
    return decimalNumber;
}

void add_value_arg(parser_t *p, instruction_t *instruction, char **command)
{
    int arg = 0;

    for (int floor = 1; split(command[p->count], ' ')[floor];
    floor++) {
        if (split(command[p->count], ' ')[floor][0] == 'r') {
            instruction->arg[arg] = my_getnbr(split(command[p->count], ' ')
                    [floor]);
                arg++;
        } else if (split(command[p->count], ' ')[floor][0] == '%') {
            if (!is_alpha(split(command[p->count], ' ')[floor][0]))
                    instruction->arg[arg] = my_getnbr(split
                            (command[p->count], ' ')[floor]);
                arg++;
        }
    }
}