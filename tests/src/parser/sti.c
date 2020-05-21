/*
** EPITECH PROJECT, 2020
** sti.c
** File description:
** sti.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_sti)
{
    char *file[] = {
            "\t.name \"lol\"",
            "\t.name \"comment\"",
            "\tsti r8, %:8, r8",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "lol") == 0);
    free(errno_);
}

Test(parser, invalid_command_sti)
{
    char *file[] = {
            "\t.name \"lol\"",
            "\t.name \"comment\"",
            "\tsti r8, %:8, %:8",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "lol") == 84);
    free(errno_);
}