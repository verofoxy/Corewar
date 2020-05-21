/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "prototype.h"

bytes_t *create_byte(int value, int position)
{
    bytes_t *element = malloc(sizeof(bytes_t));

    if (!element)
        return (NULL);
    element->value = value;
    element->position = position;
    element->type = UNINITIALISE;
    return (element);
}

node_t *set_byte(int size, node_t *park, bytes_t *tmp, type_t type)
{
    for (int i = 0; i < size; i++) {
        tmp = park->element;
        tmp->type = type;
        park = park->next;
    }
    return (park);
}

int *get_paramtype(int instruction, char *bin)
{
    int *result = malloc(sizeof(int) * 5);
    int nb_type = 0;

    if (!bin || !result)
        return NULL;
    for (int i = 0; i < 4; i++) {
        if (bin[i * 2] == 0 && bin[i * 2 + 1] == 0)
            continue;
        if (bin[i * 2] == 0 && bin[i * 2 + 1] == 1)
            result[i + 1] = REGISTER;
        else if (bin[i * 2] == 1 && bin[i * 2 + 1] == 0)
            result[i + 1] = is_index(instruction, i) == true ? INDEX : DIRECT;
        else
            result[i + 1] = is_index(instruction, i) == true ? INDEX : INDIRECT;
        nb_type++;
    }
    result[0] = nb_type;
    free(bin);
    return (result);
}

void free_codechampion(linked_list_t *code)
{
    node_t *tmp = code->head;
    node_t *tmp_2 = code->head->next;
    bytes_t *to_free = tmp->element;

    while (tmp_2) {
        to_free = tmp->element;
        free(to_free);
        tmp = tmp_2;
        tmp_2 = tmp_2->next;
    }
    to_free = tmp->element;
    free(to_free);
    list_destroy(code);
    free(code);
}

node_t *tab_to_byte(int *type, node_t *park, bytes_t *element)
{
    int posibility[] = {REGISTER, INDEX, DIRECT, INDIRECT};
    int size[] = {1, 2, 4, 4};
    int point = 0;

    for (int i = 1; i <= type[0]; i++)
    {
        for (; type[i] != posibility[point]; point++)
            ;
        park = set_byte(size[point], park, element, posibility[point]);
        point = 0;
    }
    return (park);
}