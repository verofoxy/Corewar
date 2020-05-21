/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** help_asm_vm.c
*/

#include "sys_lib.h"

void help_asm(void)
{
    my_printf("USAGE\n");
    my_printf("./asm file_nam[.s]\n");
    my_printf("DESCRIPTION\n");
    my_printf("file_name file in assembly language to be converted into ");
    my_printf("file_name.cor, an executable in the Virtual Machine.\n");
}

void help_vm(void)
{
    my_printf("USAGE./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_printf("[-a load_address] prog_name] ...\n");
    my_printf("DESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle execution");
    my_printf(" (if the round isn’t\n");
    my_printf("already over) with the following format: 32 bytes/line\n");
    my_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_printf("-n prog_number sets the next program’s number. By default, the");
    my_printf(" first free number\n");
    my_printf("in the parameter order\n");
    my_printf("-a load_address sets the next program’s loading address. ");
    my_printf("When no address is\n");
    my_printf("specified, optimize the addresses so that the ");
    my_printf("processes are as far\n");
    my_printf("away from each other as possible. The addresses ");
    my_printf("areMEM_SIZE modulo.\n");
}