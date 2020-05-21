/*
** EPITECH PROJECT, 2020
** parser.h
** File description:
** parser.h
*/
#ifndef __parser__
#define __parser__
#define and &&
#define or ||
#include <stdbool.h>
#include "op.h"
#include "my.h"
#include "linked_list.h"
#include "lexer.h"

char *arg_parser[16][11];

typedef struct parser_s {
    int count;
    int nb_byte;
    linked_list_t label;
    linked_list_t list_instruction;
    linked_list_t instruction;
    char *file_name;
    bool name;
    bool comment;
} parser_t;

typedef struct type_param_s{
    char *type;
    int valeur;
}lol;

typedef struct node_instruction{
    char **arg;
    int index_instruction;
    int line_in_file;
    bool index;
} node_instruction_t;

typedef struct label_s{
    int line;
} label_t;

char *is_write(char *file);
short swap_short(short number);
int prog_sizes(linked_list_t *code, linked_list_t *label);
char **split_instruction(char *str);
bool check_direct(char *str, linked_list_t *list);
bool check_register(char *str);
bool check_indirect(char *str, struct linked_list_s *list);
bool valid_command(char **command, op_t lol, parser_t *Parser);
bool detect_header(parser_t *p, char **command);
int parser(char **command, errno_t *errno_, char *name_file);
char **catch_label(char **command, parser_t *p);
char *my_strcat(char *dest, char const *src);
int translate(parser_t *p, char **command);
#endif //INC_007D10D12E0D4CA296328B2A23113077
