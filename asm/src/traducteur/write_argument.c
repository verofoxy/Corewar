/*
** EPITECH PROJECT, 2020
** translate_two.c
** File description:
** translate_two.c
*/

#include "traducteur.h"
#include <unistd.h>

int calc_up_byte(node_t *n, linked_list_t *l, int line_label)
{
    int res_byte = 0;
    char *str = NULL;
    node_instruction_t *instruction = ((node_instruction_t *)n->element);
    int i = count_array(((node_instruction_t *)n->previous->element)->arg);

    for (; n && instruction->line_in_file != line_label; n = n->previous) {
        instruction = ((node_instruction_t *)n->element);
        res_byte -= 1;
        if (!instruction->index)
            res_byte -= 1;
        for (; i != -1; i--) {
            str = instruction->arg[i];
            if (str == NULL)
                continue;
            if (check_register(str)) {
                res_byte -= T_REG;
            } else if (check_direct(str, l)) {
                res_byte -= 4;
            } else {
                res_byte -= 2;
            }
        }
        i = count_array(((node_instruction_t *)n->previous->element)->arg);
    }
    return res_byte;
}

int calc_down_byte(node_t *n, int i, linked_list_t *l, int line_label)
{
    int res_byte = 0;
    char *str = NULL;
    node_instruction_t *instruction = ((node_instruction_t *)n->element);

    for (; n && instruction->line_in_file != line_label; n = n->next) {

        instruction = ((node_instruction_t *)n->element);
        res_byte += 1;
        if (!instruction->index)
            res_byte += 1;
        for (int args = 0; instruction->arg[args]; i++, args++) {
            str = instruction->arg[args];
            if (check_register(str))
                res_byte += 1;
            else if (check_direct(str, l)) {
                res_byte += is_index(instruction->index_instruction + 1, args)
                        ? 2 : 4;
            } else
                res_byte += 2;
        }
        i = 0;
        if (instruction->line_in_file + 1 == line_label)
            break;
    }
    return res_byte;
}


int write_argument_two(node_t *node_instruction, int fd, int i,
linked_list_t *list_label)
{
    int swap = 0;
    char **str =
    split(((node_instruction_t *)node_instruction->element)->arg[i], ' ');
    label_t *label = NULL;
    node_instruction_t *instruction = ((node_instruction_t *)
            node_instruction->element);

    if (str[0][0] == DIRECT_CHAR && str[0][1] != LABEL_CHAR) {
        swap = my_getnbr(str[0]);
        swap = is_index(instruction->index_instruction + 1, i) ?
        (int) swap_short((short) swap) : swap_endian(swap);
        write(fd, &swap, is_index(instruction->index_instruction + 1, i) ?
        2 : 4);
    } else if (str[0][0] == DIRECT_CHAR && str[0][1] == LABEL_CHAR) {
        label = ((label_t *)get_element_from_tag(list_label, str[0] + 2));
        if (label->line > instruction->line_in_file) {
            swap = calc_down_byte(node_instruction, i + 1, list_label,
            label->line);
            swap = is_index(instruction->index_instruction + 1, i) ?
            (int) swap_short((short) swap) : swap_endian(swap);
            write(fd, &swap, is_index(instruction->index_instruction + 1, i)
            ? 2 : 4);
        } else {
            swap = calc_up_byte(node_instruction->previous, list_label,
                    label->line);
            swap = is_index(instruction->index_instruction + 1, i) ?
            (int) swap_short((short) swap) : swap_endian(swap);
            write(fd, &swap, is_index(instruction->index_instruction + 1, i)
            ? 2 : 4);}
    } else {
        label = ((label_t *)get_element_from_tag(list_label, str[0] + 2));
        if (label->line > instruction->line_in_file) {
            swap = swap_endian(calc_down_byte(node_instruction->next, i + 1,
                    list_label, label->line));
            write(fd, &swap, T_IND);
        } else {
            swap = swap_endian(calc_up_byte(node_instruction->previous,
                    list_label, label->line));
            write(fd, &swap, T_IND);
        }
    }
    return 0;
}

int write_argument(node_t *n, int fd, linked_list_t *l)
{
    int swap = 0;
    char **str = NULL;

    for (int i = 0; ((node_instruction_t *)n->element)->arg[i]; i++) {
        str = split(((node_instruction_t *)n->element)->arg[i], ' ');
        if (str[0][0] == 'r') {
            swap = my_getnbr(str[0]);
            write(fd, &swap, T_REG);
        } else {
            write_argument_two(n, fd, i, l);
        }
    }
    return 0;
}

