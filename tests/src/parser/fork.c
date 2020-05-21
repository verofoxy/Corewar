/*
** EPITECH PROJECT, 2020
** fork.c
** File description:
** fork.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_fork)
{
    char *file[] = {
            "\t.name \"lol\"",
            "\t.name \"comment\"",
            "\tfork %:959",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "lol") == 0);
    free(errno_);
}

Test(parser, invalid_command_fork)
{
    char *file[] = {
            "\t.name \"lol\"",
            "\t.name \"comment\"",
            "\tfork r8, %:8, %:8",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "lol") == 84);
    free(errno_);
}