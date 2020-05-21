/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "instruction.h"
#include "errors_vm.h"

int nb_process(arena_t *arena)
{
    int number = 0;

    for (int i = 0; i < arena->nb_player; i++)
        number += arena->number[i].is_alive ? 1 : 0;
    return number;
}

void destroy_all(arena_t *arena)
{
    for (int i = 0; i < arena->nb_process; i++) {
        destroy_system(&arena->process[i]);
    }
    destroy_arena(arena);
}

int game_loop(arena_t *arena)
{
    int winner = 0;
    char *name;

    while (nb_process(arena) != 1) {
        for (int i = 0; i < arena->nb_process; i++)
            wait_order(arena, i);
        is_alive(arena);
        update_cycle(arena);
    }
    for (int i = 0; i < arena->nb_player; i++)
        if (arena->number[i].is_alive) {
            winner = arena->number[i].number;
            break;
        }
    for (int i = 0; i < arena->nb_process; i++)
        if (winner == arena->process[i].number)
            name = arena->process[i].name;
    print("The player %d (%s) won.\n", winner, name);
    return (0);
}

int main(int argc, char *argv[])
{
    arena_t *arena = create_arena();
    sys_t *sys = NULL;
    args_t *args = check_arg((const char **)argv);

    if (argc <= 2 || !arena)
        return (84);
    for (int i = 0; i < argc - 1; i++) {
        sys = create_system(argv[i + 1], i + 1);
        if (sys == NULL)
            continue;
        arena->process = add_process(arena, (MEM_SIZE /
        (arena->nb_process + 1)) * (arena->nb_process), *sys);
    }
    if (arena->nb_player < 2)
        return 84;
    game_loop(arena);
    destroy_all(arena);
    (void)args;
    return 0;
}