/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** st.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, invalid_command_st)
{

    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tst rr",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "thomas") == 84);
    free(errno_);
}