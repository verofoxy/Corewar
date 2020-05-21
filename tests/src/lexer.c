/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lexer.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "../../include/m_errno.h"
#include "../../include/asm.h"

Test(lexer, check_valid_command)
{
    char *str[] = {
            ".name \"yann\"",
            ".comment \"sdfghfds\"",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));

    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    lexer(errno_, str);
    cr_assert(errno_->exit == SUCCESS);
    cr_assert(errno_->value == NOT_ERROR);
    free(errno_);
}

Test(lexer, check_valid_command2)
{
    char *str[] = {
            "fork	%%:tir",
            "zjmp	%%:bite",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));

    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    lexer(errno_, str);
    cr_assert(errno_->exit == SUCCESS);
    cr_assert(errno_->value == NOT_ERROR);
    free(errno_);
}

Test(lexer, check_not_valid_command)
{
    char *str[] = {
            ".namezerf \"yann\"",
            ".comme \"sdfghfds\"",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));

    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    lexer(errno_, str);
    cr_assert(errno_->exit != SUCCESS);
    cr_assert(errno_->value == ERROR_SYNTAXE_ARG);
    free(errno_);
}

Test(lexer, check_not_valid_command2)
{
    char *str[] = {
            "fork	%%:tir",
            "zjm	%%:bite",
            NULL
    };
    errno_t *errno_ = malloc(sizeof(errno_t));

    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);
    lexer(errno_, str);
    cr_assert(errno_->exit != SUCCESS);
    cr_assert(errno_->value == ERROR_SYNTAXE_ARG);
    free(errno_);
}