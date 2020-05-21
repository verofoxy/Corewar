/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "lexer.h"
#include "linked_list.h"
#include "traducteur.h"

bool check_args(node_t *n, linked_list_t *l)
{
    char **str = NULL;
    for (int i = 0; ((node_instruction_t *)n->element)->arg[i]; i++) {
        str = split(((node_instruction_t *)n->element)->arg[i],
                SEPARATOR_CHAR);
        if (str[0][0] == 'r')
            return check_register(str[0]);
        if (str[0][0] == DIRECT_CHAR)
                return check_direct(str[0], l);
        else
            return check_indirect(str[0], l);
    }
    return false;
}

bool check_command(node_t *n, linked_list_t *l)
{
    int i = 0;

    for (; op_tab[i].mnemonique != NULL; i++)
        if (m_strcmp(n->tag, op_tab[i].mnemonique) == 0)
            break;
    if (i != 16) {
        ((node_instruction_t *)n->element)->index_instruction = i;
        if (op_tab[i].nbr_args ==
        count_array(((node_instruction_t *)n->element)->arg))
            return check_args(n, l);
        return false;
    } else
        return false;
}

void add_instruction(char *str, linked_list_t *l, int line)
{
    char **str_array = split(str, ' ');
    char *tag = str_array[0];
    int i = 1;
    node_instruction_t *n = malloc(sizeof(node_t));

    if (str[0] == '\0' || str[0] == '\n'
        || m_strcmp(str_array[0], NAME_CMD_STRING) == 0
        || m_strcmp(str_array[0], COMMENT_CMD_STRING) == 0)
        return;
    n->line_in_file = line;
    n->index = detect_dont_take_coding_bit(tag);
    n->arg = malloc(sizeof(char *) * (count_array(str_array) + 1));
    for (; str_array[i] != NULL; i++) {
        n->arg[i - 1] = str_array[i];
        n->arg[i - 1][my_strlen(str_array[i])] = 0;
    }
    n->arg[i - 1] = NULL;
    add_node(l, n, tag);
}

int parser(char **command, errno_t *errno_, char *file_name)
{
    parser_t *parser = malloc(sizeof(parser_t));

    CHECK_MALLOC(parser)
    if (!detect_header(parser, command))
        return (84);
    parser->file_name = file_name;
    if (command == NULL || errno_->value != NOT_ERROR) return 84;
    parser->list_instruction.head = NULL;
    parser->nb_byte = 0;
    command = catch_label(command, parser);
    for (int i = 0; command[i]; i++)
        add_instruction(command[i], &parser->list_instruction, i);
    for (node_t *n = parser->list_instruction.head; n != NULL; n = n->next)
        if (check_command(n, &parser->label) == false)
            return 84;
    return translate(parser, command);
}
