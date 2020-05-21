/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#include "instruction.h"

/*

void dump_arena(arena_t *arena)
{
    for (int i = 0; i < 100; i++) {
        print("%d ", arena->cases[i].value);
    }
    print("\n");
}

*/

void ld_champ_code(sys_t *champion, arena_t *arena, int start)
{
    node_t *tmp = get_node_from_index(champion->code, champion->pc);
    bytes_t *park = NULL;

    for (int i = 0; tmp; i++) {
        park = tmp->element;
        arena->cases[start + i].value = park->value;
        arena->cases[start + i].type = park->type;
        tmp = tmp->next;
    }
    champion->pc = start;
}

soul_t *add_number_arena(arena_t *arena, int number)
{
    soul_t *new_numbers = NULL;

    arena->nb_player++;
    new_numbers = malloc(sizeof(soul_t) * arena->nb_player);
    for (int i = 0; i < arena->nb_player - 1; i++)
        new_numbers[i] = arena->number[i];
    new_numbers[arena->nb_player - 1].number = number;
    new_numbers[arena->nb_player - 1].last_live = 0;
    new_numbers[arena->nb_player - 1].is_alive = true;
    free(arena->number);
    arena->number = new_numbers;
    return new_numbers;
}

sys_t *add_process(arena_t *arena, int adress, sys_t process)
{
    sys_t *new_set = NULL;
    bool new = true;

    new_set = malloc(sizeof(sys_t) * (arena->nb_process + 1));
    if (new_set == NULL)
        exit(84);
    for (int i = 0; i < arena->nb_process; i++)
        new_set[i] = arena->process[i];
    ld_champ_code(&process, arena, adress);
    new_set[arena->nb_process] = process;
    arena->nb_process++;
    for (int i = 0; i < arena->nb_player; i++)
        new = process.number == arena->number[i].number ? false : new;
    if (new || arena->nb_player == 0) {
        arena->number = add_number_arena(arena, process.number);
    }
    free(arena->process);
    return (new_set);
}

arena_t *create_arena(void)
{
    arena_t *arena = malloc(sizeof(arena_t));

    if (!arena)
        return (NULL);
    for (int i = 0; i < MEM_SIZE; i++) {
        arena->cases[i].value = 0;
        arena->cases[i].type = UNINITIALISE;
        arena->cases[i].position = i;
    }
    arena->process = NULL;
    arena->number = 0;
    arena->nb_player = 0;
    arena->cycle_to_die = CYCLE_TO_DIE;
    arena->nb_process = 0;
    return (arena);
}