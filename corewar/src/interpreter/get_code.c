/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "prototype.h"
#include "linked_list.h"
#include "instruction.h"

bytes_t *get_byte_from_pos(arena_t *arena, int position)
{
    bytes_t *result = &arena->cases[position];
    return result;
}

linked_list_t *get_bytecode(char *filename)
{
    int fd = open(filename, O_RDONLY);
    int octet = 0;
    bytes_t *tmp = NULL;
    linked_list_t *head = malloc(sizeof(linked_list_t));

    CHECK_MALLOC(head);
    head->head = NULL;
    head->tail = NULL;
    if (fd == -1)
        return (NULL);
    for (int position = 0; read(fd, &octet, 1) != 0; position++) {
        tmp = create_byte(octet, position);
        if (tmp == NULL || add_node(head, tmp, "byte") == 84) {
            close(fd);
            return NULL;
        }
    }
    close(fd);
    return head;
}

// call get_bytecode
// call set_type
// free_codechampion