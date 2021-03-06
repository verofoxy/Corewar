/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** ld.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_ld)
{
char *file[] = {
        "\t.name \"popo\"",
        "\t.comment \"popo\"",
        "\tld %15, r5",
        NULL
};
errno_t *errno_ = malloc(sizeof(errno_t));
set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
cr_assert(parser(file, errno_, "yann") == 0);
free(errno_);
}

Test(parser, invalid_command_ld)
{
char *file[] = {
        "\t.name \"popo\"",
        "\t.comment \"popo\"",
        "\tld %15",
        NULL
};
errno_t *errno_ = malloc(sizeof(errno_t));
set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
cr_assert(parser(file, errno_, "marguyne") == 84);
free(errno_);
}