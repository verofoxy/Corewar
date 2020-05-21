/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lfork.c
*/

#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_lfork)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tlfork %23",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "nathalie") == 0);
    free(errno_);
}

Test(parser, invalid_command_lfork)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tlfork rr, 5, ;",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "britta") == 84);
    free(errno_);
}