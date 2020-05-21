/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instruction.h
*/

#ifndef CPE_COREWAR_2019_INSTRUCTION_H
#define CPE_COREWAR_2019_INSTRUCTION_H

#include "linked_list.h"
#include "struct.h"

#define LIVE        1
#define LD          2
#define ST          3
#define ADD         4
#define SUB         5
#define AND         6
#define OR          7
#define XOR         8
#define ZJMP        9
#define LDI         10
#define STI         11
#define FORK        12
#define LLD         13
#define LLDI        14
#define LFORK       15
#define AFF         16

typedef struct instruction {
    int instruction_id;
    int nb_arg;
    int cycle;
    void (*callback)();
}instruction_t;

typedef struct system_instruction_s {
    int carry;
    linked_list_t *code;
    bytes_t args[MAX_ARGS_NUMBER];
    int pc;
    int *registers;
    int number;
    char name[PROG_NAME_LENGTH + 1];
    char *filename;
    int current_act;
    int waiting;
    int cursor;
}sys_t;

typedef struct soul_s {
    int number;
    int last_live;
    bool is_alive;
} soul_t;

typedef struct arena_s
{
    int cycle_to_die;
    int nb_process;
    bytes_t cases[MEM_SIZE];
    sys_t *process;
    soul_t *number;
    int nb_player;
} arena_t;

void op_ld(arena_t *arena, int process);
void op_st(arena_t *arena, int process);
void op_add(arena_t *arena, int process);
void op_sub(arena_t *arena, int process);
void op_and(arena_t *arena, int process);
void op_or(arena_t *arena, int process);
void op_xor(arena_t *arena, int process);
void op_zjmp(arena_t *arena, int process);
void op_aff(arena_t *arena, int process);
void op_live(arena_t *arena, int process);
void op_lld(arena_t *arena, int process);
void op_lldi(arena_t *arena, int process);
void op_ldi(arena_t *arena, int process);
void op_sti(arena_t *arena, int process);
void op_fork(arena_t *arena, int process);
void op_lfork(arena_t *arena, int process);

void (*get_instruction(int id))(sys_t *);
sys_t *add_process(arena_t *arena, int adress, sys_t process);
arena_t *create_arena(void);
sys_t *create_system(char *filename, int number);
void destroy_system(sys_t *sys);
void destroy_arena(arena_t *arena);

int read_parameter(int size, int start_position, arena_t *arena);
bool read_instruction(arena_t *arena, int process);
bytes_t *get_byte_from_pos(arena_t *arena, int position);
void get_champion_name(sys_t *sys);
void write_byte(arena_t *arena, int value, int pos, int size);
void update_cycle(arena_t *arena);
void wait_order(arena_t *arena, int process);
void is_alive(arena_t *arena);


static const instruction_t ALL_INSTRUCTIONS[] = {
        {LIVE, 1, 10, op_live},
        {LD, 2, 5, op_ld},
        {ST, 2, 5, op_st},
        {ADD, 3, 10, op_add},
        {SUB, 3, 10, op_sub},
        {AND, 3, 6, op_and},
        {OR, 3, 6, op_or},
        {XOR, 3, 6, op_xor},
        {ZJMP, 1, 20, op_zjmp},
        {LDI, 3, 25, op_ldi},
        {STI, 3, 25, op_sti},
        {FORK, 1, 800, op_fork},
        {LLD, 2, 10, op_lld},
        {LLDI, 3, 50, op_lldi},
        {LFORK, 1, 1000, op_lfork},
        {AFF, 1, 2, op_aff}};
static const int NB_INSTRUCTIONS =
    sizeof(ALL_INSTRUCTIONS) / sizeof(instruction_t);

#endif
