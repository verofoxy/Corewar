/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "prototype.h"

void set_parameter(linked_list_t *head)
{
    node_t *park = head->head;
    bytes_t *tmp = park->element;
    bytes_t *tmp_2 = park->next->element;
    int *params = NULL;

    while (park != NULL) {
        while (tmp_2 && tmp_2->type != CODING_BYTE && park && park->next) {
            park = park->next;
            tmp = park->element;
            tmp_2 = park->next == NULL ? NULL : park->next->element;
        }
        if (!tmp_2)
            return;
        params = get_paramtype(tmp->value, number_to_byte(tmp_2->value));
        park = park->next->next;
        park = tab_to_byte(params, park, tmp);
        free(params);
        tmp = park->element;
        tmp_2 = park->next->element;
    }
}

void set_codingbyte(linked_list_t *head)
{
    node_t *park = head->head;
    bytes_t *tmp = park->element;
    bool coding = false;

    for (node_t *stack = park; stack != NULL; stack = stack->next) {
        tmp = stack->element;
        if (coding) {
            tmp->type = CODING_BYTE;
            coding = false;
        }
        if (tmp->type == INSTRUCTION && no_codingoffset(tmp->value) == 0)
            coding = true;
    }
}

void set_instructionbyte(linked_list_t *head)
{
    node_t *park = head->head;
    bytes_t *tmp = park->element;
    bytes_t *tmp_2;
    int offset = 0;

    while (tmp->type != INSTRUCTION) {
        park = park->next;
        tmp = park->element;
    }
    while (park != NULL) {
        tmp = park->element;
        tmp->type = INSTRUCTION;
        tmp_2 = park->next->element;
        offset = get_paramsize(tmp->value, tmp_2->value);
        if (offset == -1)
            return;
        for (int i = 0; i < offset; i++)
            park = park->next;
    }
}

node_t *set_bench_type(type_t type, int size, node_t *code)
{
    bytes_t *park;

    for (int i = 0; i < size; i++) {
        park = code->element;
        park->type = type;
        code = code->next;
    }
    return (code);
}

void set_name_comment(linked_list_t *head)
{
    node_t *tmp = head->head;

    tmp = set_bench_type(EXEC_MAGIC, 4, tmp);
    tmp = set_bench_type(NAME, PROG_NAME_LENGTH, tmp);
    tmp = set_bench_type(UNINITIALISE, 4, tmp);
    tmp = set_bench_type(PROG_SIZE, 4, tmp);
    tmp = set_bench_type(COMMENT, COMMENT_LENGTH, tmp);
    tmp = set_bench_type(UNINITIALISE, 4, tmp);
    tmp = set_bench_type(INSTRUCTION, 1, tmp);
}