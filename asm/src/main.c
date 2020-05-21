/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "m_errno.h"
#include "asm.h"
#include "parser.h"

int main(int ac, const char *argv[])
{
    FILE *fd;
    char **file;
    errno_t *errno_ = malloc(sizeof(errno_t));

    CHECK_NULL(errno_)
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    if (ac > 1) {
        fd = fopen(argv[1], "r");
        if (fd == NULL) return 84;
        file = set_double_tab_from_file(fd);
        fclose(fd);
        lexer(errno_, file);
        if (parser(file, errno_, argv[1]) != 0) return 84;
    }
    if (errno_->value != NOT_ERROR)
        return (84);
    free(errno_);
    return (SUCCESS);
}