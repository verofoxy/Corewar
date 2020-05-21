/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lldi.c
*/


#include "../../../include/parser.h"
#include <criterion/criterion.h>

Test(parser, valid_command_lldi)
{
    char *file[] = {
            "\t.name \"popo\"",
            "\t.comment \"popo\"",
            "\tlldi  %24, r2, r3",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    cr_assert(parser(file, errno_, "emilie") == 0);
    free(errno_);
}
