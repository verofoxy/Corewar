/*
** EPITECH PROJECT, 2020
** translate.c
** File description:
** translate.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "traducteur.h"

char *my_calloc(char *str, int new_size)
{
    int size = my_strlen(str);

    str = realloc(str, new_size + 1);
    CHECK_MALLOC(str)
    for (int i = size; i < new_size + 1; i++)
        str[i] = 0;
    return (str);
}

int swap_endian(int number)
{
    int byte0 = (number & 0x000000FF) >> 0;
    int byte1 = (number & 0x0000FF00) >> 8;
    int byte2 = (number & 0x00FF0000) >> 16;
    int byte3 = (number & 0xFF000000) >> 24;
    return ((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

short swap_short(short number)
{
    int byte0 = (number & 0x00FF) >> 0;
    int byte1 = (number & 0xFF00) >> 8;

    return ((byte0 << 8) | (byte1 << 0));
}

int search_coding_byte(node_t *n)
{
    int coding_byte = 0;
    int i = 0;

    for (; ((node_instruction_t *)n->element)->arg[i]; i++) {
        if (split(((node_instruction_t *)n->element)->arg[i], ' ')[0][0] ==
        'r') {
            coding_byte |= 1;
        }else if (split(((node_instruction_t *)n->element)->arg[i], ' ')[0][0]
        == DIRECT_CHAR) {
            coding_byte |= 2;
        } else {
            coding_byte |= 3;
        }
        coding_byte <<= 2;
    }
    for (; i < MAX_ARGS_NUMBER - 1; i++)
        coding_byte <<= 2;
    return coding_byte;
}

int translate(parser_t *p, char **command)
{
    char *filename = is_write((p->file_name));
    FILE *filedesc = fopen(filename, "w");
    int swap = swap_endian(COREWAR_EXEC_MAGIC);
    int prog = prog_sizes(&p->list_instruction, &p->label);
    if (filedesc == NULL)
        return 84;
    write(filedesc->_fileno, &swap, 4);
    write(filedesc->_fileno, my_calloc(split(command[0], '"')[1],
            PROG_NAME_LENGTH), PROG_NAME_LENGTH);
    swap = swap_endian(0);
    write(filedesc->_fileno, &swap, 4);
    swap = swap_endian(prog);
    write(filedesc->_fileno, &swap, 4);
    write(filedesc->_fileno, my_calloc(split(command[1], '"')[1],
            COMMENT_LENGTH), COMMENT_LENGTH);
    swap = swap_endian(0);
    write(filedesc->_fileno, &swap, 4);

    for (node_t *n = p->list_instruction.head; n; n = n->next) {
        swap = (int) op_tab[((node_instruction_t *)n->element)
                ->index_instruction].code;
        write(filedesc->_fileno, &swap, 1);
        for (int i = 0; ((node_instruction_t *)n->element)->arg[i]; i++) {
            ((node_instruction_t *)n->element)->arg[i] = split((
                (node_instruction_t *)n->element)->arg[i], SEPARATOR_CHAR)[0];
        }
        if (!((node_instruction_t *)n->element)->index) {
            swap = search_coding_byte(n);
            write(filedesc->_fileno, &swap, 1);
        }
        write_argument(n, filedesc->_fileno, &p->label);
    }
    return 0;
}
