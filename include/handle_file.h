/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** handel_file.h
*/

#ifndef handle_file_H
#define handle_file_H

#include <stdio.h>
#include <stdlib.h>

char **set_double_tab_from_file(FILE *fd);
void free_double_tab(void **tab);

#endif