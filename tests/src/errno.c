/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** errno.c
*/

#include <criterion/criterion.h>
#include "../../include/m_errno.h"

Test(lexer, check_fill_out_errno_SUCCESS)
{
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer succeed", SUCCESS, NOT_ERROR);

    cr_assert_str_eq(errno_->errno_msg, "Lexer succeed");
    cr_assert(errno_->exit == SUCCESS);
    cr_assert(errno_->value == NOT_ERROR);
    free(errno_);
}

Test(lexer, check_fill_out_errno_CRACH)
{
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_(errno_, "Lexer fail", CRACH, ERROR_OPP);

    cr_assert_str_eq(errno_->errno_msg, "Lexer fail");
    cr_assert(errno_->exit == CRACH);
    cr_assert(errno_->value == ERROR_OPP);
    free(errno_);
}

Test(lexer, choose_errno_type_NOT_ERROR)
{
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_from_type(errno_, NOT_ERROR);

    cr_assert_str_eq(errno_->errno_msg, "not error detected");
    cr_assert(errno_->exit == SUCCESS);
    cr_assert(errno_->value == NOT_ERROR);
    free(errno_);
}

Test(lexer, choose_errno_type_ERROR_NBR_ARG)
{
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_from_type(errno_, ERROR_NBR_ARG);

    cr_assert_str_eq(errno_->errno_msg, "invalid nbr arg");
    cr_assert(errno_->exit == CRACH);
    cr_assert(errno_->value == ERROR_NBR_ARG);
    free(errno_);
}

Test(lexer, choose_errno_type_ERROR_SYNTAXE)
{
    errno_t *errno_ = malloc(sizeof(errno_t));
    set_errno_from_type(errno_, ERROR_SYNTAXE);

    cr_assert_str_eq(errno_->errno_msg, "invalide syntaxe");
    cr_assert(errno_->exit == CRACH);
    cr_assert(errno_->value == ERROR_SYNTAXE);
    free(errno_);
}
