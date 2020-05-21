/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** arg.c
*/

#include "my.h"
#include "errors_vm.h"

void set_nbr_cycle(args_t *arg, char *str)
{
    arg->nbr_cycle = str;
}

void set_prog_nbr(args_t *arg, char *str)
{
    arg->prog_number = str;
}

void set_load_address(args_t *arg, char *str)
{
    arg->load_address = str;
}

int rigor(const char *value_arg)
{
    int check = 0;
    const char *labelizing = LABELIZING_CHAR;

    if (!value_arg)
        return (EXIT_FAILURE);
    for (int i = 0; value_arg[i]; i++, check = 0) {
        for (int j = 0; labelizing[j]; j++) {
            check += (value_arg[i] == labelizing[j]) ? (1) : (0);
        }
        if (!check)
            return (EXIT_FAILURE);
    }
    return (EXEC_SUCCESS);
}

args_t *check_arg(const char **av)
{
    args_t *arg = malloc(sizeof(args_t));
    void (*tab_func[]) (args_t *, char *) = FUNC_FLAGS;
    const char *flags[] = STR_FLAGS;

    CHECK_MALLOC(arg)
    for (int i = 1; av[i]; i++) {
        for (int nf = 0; flags[nf]; nf++)
            if (m_strcmp((char *)flags[nf], (char *)av[i]) == 0) {
                rigor(av[i + 1]);
                (flags[nf][1] == 'h') ? ((*tab_func[nf]) (arg, (char *)av[i]))
                : ((*tab_func[nf]) (arg, (char *)av[i + 1]));
                break;
            }
        arg->pos_exe = i;
    }
    return (arg->load_address && arg->prog_number && !arg->nbr_cycle)
            ? (arg) : (NULL);
}
