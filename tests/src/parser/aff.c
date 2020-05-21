/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** aff.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_aff)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\taff r1",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "soeur_jordan") == 0);
    free(errno_);
}

Test(parser, invalid_command_aff)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\taff rr, 5, ;",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "sauvage") == 84);
    free(errno_);
}