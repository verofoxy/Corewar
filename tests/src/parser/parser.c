/*
** EPITECH PROJECT, 2020
** parser.c
** File description:
** parser.c
*/

#include "../../../include/parser.h"
#include "errno.h"
#include <criterion/criterion.h>

Test(parser, invalid_header)
{
    char *file[] = {
            "\tname 'popo'",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "toto") == 84, "je suis passerr\n");
}

Test(parser, valid_header)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "toto") == 0);
    free(errno_);
}

Test(parser, invalid_command_add)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tadd r5, %8, r4 ",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "toto") == 84);
    free(errno_);
}

Test(parser, invalid_command_live)
{
    char *file[] = {
            "\t.name \"popo\"clear"
            "",
            "\t.comment \"popo\"",
            "\tlive rt, %:4",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert(parser(file, errno_, "toto") == 84);
    free(errno_);
}
