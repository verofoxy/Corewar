/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** op_lexer.c
*/

#include "asm.h"

int check_label(int *label_commande, int commande)
{
    for (int i = 0; label_commande[i]; i++)
        if (label_commande[i] == commande)
            return (EXIT_SUCCESS);
    return (ERROR_SYNTAXE_ARG);
}

int check_commande_label(char *str, int *tab, int *i)
{
    int commande = 0;
    int check;

    if (str[*i] == '.' || (str[*i] == '\t' && str[*i] == ' ' && str[*i]))
        i[0]++;
    if (str[*i] == '\t' || str[*i] == ' ')
        return ERROR_NBR_ARG;
    if (str[*i] == ' ' || str[*i] == '\0' || str[*i] == '\t' || str[*i] == ',')
        return (ERROR_NBR_ARG);
    for (; str[*i]; i[0]++) {
        if ((str[*i] == ':'))
            return (EXIT_SUCCESS);
        if ((str[*i] == '%' && (str[*i + 1] != ':')))
            return (EXIT_SUCCESS);
        else if (str[*i] == ',')
            return (EXIT_SUCCESS);
        else if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != ':')
            commande += str[*i];
        else if (commande > 0 && (str[*i] == '\t' || str[*i] == ' ')) {
            check = check_label(tab, commande);
            return (check);
        } else
            return (ERROR_NBR_ARG);
    }
    return (EXIT_SUCCESS);
}

int check_arg(char *str, int *i)
{
    i[0]++;
    if (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\0')
        return (ERROR_VALUE);
    if (str[*i] == '-')
        i[0]++;
    for (; str[*i] && ((str[*i] >= '0' && str[*i]
    <= '9') || (str[*i] >= 'a' && str[*i] <= 'z')); i[0]++);
    if (str[*i] == ':' || str[*i] == ' ' || str[*i] == ','  || str[*i] == '\0')
        return (EXIT_SUCCESS);
    return (ERROR_VALUE);
}