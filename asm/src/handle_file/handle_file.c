/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** handle_file.c
*/

#include "linked_list.h"
#include "my.h"
#include "handle_file.h"

char **set_double_tab_from_file(FILE *fd)
{
    size_t n = 0;
    int i = 0;
    int nb = 0;
    char **file = malloc(sizeof(char *) * 1000);

    CHECK_MALLOC(file)
    for (; nb != -1;) {
        file[i] = NULL;
        nb = getline(&file[i], &n, fd);
        if (nb != -1)
            file[i++][nb - 1] = '\0';
    }
    file[i] = NULL;
    return (file);
}

void free_double_tab(void **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}