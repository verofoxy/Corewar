/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** errors_vm.h
*/

#ifndef CPE_COREWAR_2019_ERRORS_VM_H
#define CPE_COREWAR_2019_ERRORS_VM_H

#include "struct.h"

#define STR_FLAGS {"-h", "-dump", "-n", "-a", NULL}
#define FUNC_FLAGS {&help_vm, &set_nbr_cycle, &set_prog_nbr, &set_load_address}
#define LABELIZING_CHAR "abcdefghijklmnopqrstuvwyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

typedef struct args_t
{
    const char *nbr_cycle;
    const char *prog_number;
    const char *load_address;
    size_t pos_exe;
} args_t;

int count_instructions_with_arg(linked_list_t *bytecode);
int compare_prog_size_instrucution(linked_list_t *bytecode);
int compare_magic_nbr(linked_list_t *bytecode);
void help_vm();
args_t *check_arg(const char **av);
#endif