/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lexer.h
*/

#ifndef LEXER_H
#define LEXER_H

#include "m_errno.h"

void lexer(errno_t *errno_, char **labelising_file);
int check_label(int *label_commande, int commande);
int check_commande_label(char *str, int *tab, int *i);
int check_arg(char *str, int *i);


int strlen_separator(char *str, char separator);
int *tab_hash_from_str(char *str, char separator, int *tab);



#endif