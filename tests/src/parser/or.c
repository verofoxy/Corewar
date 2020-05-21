/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** or.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_or)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tor r5, %4, r1",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "valerie") == 0);
    free(errno_);
}
