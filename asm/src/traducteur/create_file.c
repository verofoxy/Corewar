/*
** EPITECH PROJECT, 2020
** create_file.c
** File description:
** create_file.c
*/

#include "traducteur.h"
/*
int has_tetrimino_extension(char *name_file)
{

}
*/

char *is_write(char *file)
{
    int size = 0;
    char *copy = NULL;
    int i = 0;

    if (file[0] == '.' && file[1] == '/')
            file +=2;
    size = my_strlen(file);
    copy = malloc(sizeof(char) * my_strlen(file) + 3);
    for (; i < size - 2; i++)
            copy[i] = file[i];
    copy[size - 2] = '.';
    copy[size - 1] = 'c';
    copy[size] = 'o';
    copy[size + 1] = 'r';
    copy[size + 2] = 0;
    return copy;
}

int size_arg(char **file, int instruction, linked_list_t *list_label)
{
    int size = 0;

    for (int i = 0; file[i] != NULL; i++) {
        size += check_register(file[i]) ? 1 : 0;
        if (!is_index(instruction, i)) {
            size += 2;
        } else {
            size += check_indirect(file[i], list_label) ? 4 : 0;
            size += check_direct(file[i], list_label) ? 4 : 0;
        }
    }
    return  size;
}

int prog_sizes(linked_list_t *code, linked_list_t *label)
{
    int prog = 0;
    node_t *tmp = code->head;
    node_instruction_t *p;

    for (; tmp; tmp = tmp->next) {
        p = tmp->element;
        prog += size_arg(p->arg, p->index_instruction, label) + 1;
        prog += p->index ? 1 : 0;
    }
    return prog;
}