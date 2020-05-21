/*
** EPITECH PROJECT, 2020
** traducteur.h
** File description:
** traducteur.h
*/
#ifndef __traducteur__
#define __traducteur__

#include "parser.h"
#include <stdlib.h>

#define SIZE_TAB_INDEX (4)

typedef struct indexes_s {
    int instruction;
    int amount;
    int position[MAX_ARGS_NUMBER];
}   indexes_t;

static const indexes_t tab_index[] = {
        {9, 1, {0}},
        {10, 2, {0, 1}},
        {11, 2, {1, 2}},
        {12, 1, {0}}
};

static char *list_not_conding_byte[] = {
        "live",
        "zjmp",
        "fork",
        "lfork",
        NULL
};

typedef struct instruction_s
{
    int id;
    int coding_byte;
    int arg[4];
} instruction_t;

void my_emset(char *str, int size, char c);
int pows(int a, int b);
int swap_endian(int number);
int write_argument(node_t *n, int fd, linked_list_t *l);
int conver_bit_to_dec(ulong n);
int search_coding_byte(node_t *n);
bool detect_dont_take_coding_bit(char *st);
bool is_index(int instruction, int position);
#endif //INC_A3421B5CA9754C03AE0056F78ACF8F65
