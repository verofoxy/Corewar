/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "prototype.h"

bool is_index(int instruction, int position)
{
    bool result = false;
    int element = 0;

    for (int i = 0; i < SIZE_TAB_INDEX; i++)
        result = instruction == tab_index[i].instruction ? true : result;
    if (!result)
        return (false);
    result = false;
    for (int i = 0; tab_index[i].instruction != instruction; i++)
        element++;
    for (int i = 0; i < tab_index[element].amount; i++)
        result = tab_index[element].position[i] == position ? true : result;
    return (result);
}

int str_to_offset(char *bin, int instruction)
{
    int offset = 2;
    int start = 0;

    for (int i = 0; i < 4; i++) {
        if (bin[start] == 0 && bin[start + 1] == 0) {
            start += 2;
            continue;
        }
        if (bin[start] == 0 && bin[start + 1] == 1)
            offset++;
        else if (bin[start] == 1 && bin[start + 1] == 0)
            offset += is_index(instruction, i) ? 2 : 4;
        else
            offset += is_index(instruction, i) ? 2 : 4;
        start += 2;
    }
    free(bin);
    return (offset);
}

int no_codingoffset(int value)
{
    int no_codingbyte[] = {1, 9, 12, 15};
    int offset[] = {5, 3, 3, 3};

    for (int i = 0; i < 4; i++) {
        if (value == no_codingbyte[i])
            return (offset[i]);
    }
    return (EXEC_SUCCESS);
}

int get_paramsize(int instruction, int coding_byte)
{
    int offset = 0;
    char *bin = NULL;

    offset = no_codingoffset(instruction);
    if (offset != 0)
        return (offset);
    bin = number_to_byte(coding_byte);
    if (bin == NULL)
        return (-1);
    return (str_to_offset(bin, instruction));
}

void set_type(linked_list_t *head)
{
    set_name_comment(head);
    set_instructionbyte(head);
    set_coding_arg(head);
    set_codingbyte(head);
    set_parameter(head);

}