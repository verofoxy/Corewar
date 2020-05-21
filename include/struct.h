/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#ifndef STRUCT
#define STRUCT
#include "sys_lib.h"

typedef struct indexes_s {
    int instruction;
    int amount;
    int position[MAX_ARGS_NUMBER];
}   indexes_t;

#define SIZE_TAB_INDEX (6)
static const indexes_t tab_index[] = {
    {9, 1, {0}}, {10, 2, {0, 1}}, {11, 2, {1, 2}}, {12, 1, {0}}, {14, 2,
    {0, 1}}, {15, 1, {0}}
};

typedef enum type_s {
    UNINITIALISE,
    EXEC_MAGIC,
    PROG_SIZE,
    NAME,
    COMMENT,
    INSTRUCTION,
    REGISTER,
    DIRECT,
    INDIRECT,
    INDEX,
    CODING_BYTE,
} type_t;

static const int sizes[] = {4, 4, 4, PROG_NAME_LENGTH, COMMENT_LENGTH, \
1, 1, 4, 4, 2, 1 };

typedef struct bytes_s {
    int value;
    int position;
    type_t type;
} bytes_t;

#endif
/* !STRUCT */
