/*
** EPITECH PROJECT, 2020
** catch_label.c
** File description:
** catch_label.c
*/

#include "parser.h"
#include <stdlib.h>

bool detect_header(parser_t *p, char **command)
{
    char *str1 = "\t.name";
    char *str2 = ".name";
    char *str3 = "\t.comment";
    char *str4 = ".comment";

    p->name = false;
    p->comment = false;
    for (int i = 0; command[i] != NULL; i++) {
        if (command[i][0] == '\0' || command[i][0] == '\n')
            continue;
        if (m_strcmp(split(command[i], ' ')[0], str1) == 0 ||
        m_strcmp(split(command[i], ' ')[0], str2) == 0)
            if (my_strlen(split(command[i], ' ')[0]) > 2)
                p->name = true;
        if (m_strcmp(split(command[i], ' ')[0], str3) == 0 ||
        m_strcmp(split(command[i], ' ')[0], str4) == 0)
            if (my_strlen(split(command[i], ' ')[0]) > 2)
                p->comment = true;
    }
    if (p->name != true || p->comment != true)
        return false;
    return true;
}

char **catch_label(char **command, parser_t *p)
{
    char *str = NULL;
    char **str_array = NULL;
    label_t *label = NULL;

    p->label.head = NULL;
    for (int i = 0; command[i] != NULL; i++) {
        if (command[i][0] != '\t' && command[i][0] != '.' && command[i][0]
        != '\n' && command[i][0] != '\0' && command[i][0] != COMMENT_CHAR) {
            label = malloc(sizeof(label_t) * 1);
            label->line = i;
            str_array = split(command[i], LABEL_CHAR);
            str = malloc(sizeof(char) * my_strlen(str_array[0]) + 1);
            str = my_strncpy(str, command[i], my_strlen(str_array[0]));
            str[my_strlen(str_array[0])] = '\0';
            if (str_array[1] == NULL or command[i][my_strlen (command[i]) -
            1] == LABEL_CHAR)
                command[i] = "\0";
            else
                command[i] = str_array[1] + 1;
            add_node(&p->label, label, str);
        } else {
            if (command[i][0] != '.' && command[i][0] != '\n' &&
            command[i][0] != '\0') command[i] += 1;
        }
    }
    return command;
}
