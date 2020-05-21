/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** and.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_and)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tand r1 ,%0,r1",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "tony") == 0);
    free(errno_);
}

Test(parser, invalid_command_and)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tand r1 ,%0",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "speedy") == 84);
    free(errno_);
}