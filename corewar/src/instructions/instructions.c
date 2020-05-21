/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instructions.c
*/

#include <stdlib.h>
#include "op.h"
#include "instruction.h"
#include "prototype.h"

void set_pc(sys_t *sys)
{
    node_t *park = sys->code->head;
    bytes_t *tmp = park->element;

    sys->pc = 0;
    while (tmp->type != INSTRUCTION) {
        park = park->next;
        tmp = park->element;
        sys->pc++;
    }
}

void set_code(sys_t *sys, char *filename)
{
    set_type(sys->code);
    get_champion_name(sys);
    set_pc(sys);
    sys->carry = 0;
    sys->filename = filename;
    sys->waiting = 0;
    sys->current_act = 0;
}

sys_t *create_system(char *filename, int number)
{
    sys_t *sys = malloc(sizeof(sys_t));

    CHECK_MALLOC(sys);
    sys->code = get_bytecode(filename);
    sys->registers = malloc(sizeof(REG_SIZE) * REG_NUMBER);
    if (sys->code == NULL || sys->registers == NULL)
        return (NULL);
    sys->number = number;
    for (int i = 0; i < REG_NUMBER; i++)
        sys->registers[i] = 0;
    sys->registers[0] = sys->number;
    set_code(sys, filename);
    return sys;
}

void destroy_system(sys_t *sys)
{
    free(sys->registers);
    free_codechampion(sys->code);
}

void (*get_instruction(int instruction_id))(sys_t *)
{
    int i = 0;

    for (i = 0; i < NB_INSTRUCTIONS; i++)
        if (ALL_INSTRUCTIONS[i].instruction_id == instruction_id)
            return ALL_INSTRUCTIONS[i].callback;
    return NULL;
}