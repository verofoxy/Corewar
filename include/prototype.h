/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#ifndef PROTOTYPE
#define PROTOTYPE
#include "struct.h"

bytes_t *create_byte(int value, int position);
linked_list_t *get_bytecode(char *filename);
int get_paramsize(int instruction, int coding_byte);
void set_instructionbyte(linked_list_t *head);
void set_type(linked_list_t *head);
void set_name_comment(linked_list_t *head);
int no_codingoffset(int value);
void set_codingbyte(linked_list_t *head);
bool is_index(int instruction, int position);
int *get_paramtype(int instruction, char *bin);
node_t *set_byte(int size, node_t *park, bytes_t *tmp, type_t type);
void free_codechampion(linked_list_t *code);
void set_parameter(linked_list_t *head);
node_t *tab_to_byte(int *type, node_t *park, bytes_t *element);
node_t *set_bench_type(type_t type, int size, node_t *code);
void set_coding_arg(linked_list_t *code);

#endif /* !PROTOTYPE */
