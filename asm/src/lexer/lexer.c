/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lexer.c
*/

#include "linked_list.h"
#include "my.h"
#include "handle_file.h"
#include "asm.h"

void label_default(char *str, int *i, int *h_cmd, errno_t *errno_)
{
    if (str[*i] == ' ' || str[*i] == '\t')
        return;
    set_errno_from_type(errno_, check_commande_label(str, h_cmd, i));
}

void label_c(char *str, int *i, errno_t *errno_)
{
    i[0]++;
    for (; str[*i] && str[*i] != '"'; i[0]++);
    if (str[*i] != '"')
        set_errno_from_type(errno_, ERROR_SYNTAXE);
}

void label_r(char *str, int *i, errno_t *errno_)
{
    if (i[0]++ == 0) {
        set_errno_from_type(errno_, ERROR_NBR_ARG);
        return;
    }
    else if ((str[*i] == ' ' || str[*i] == '\t')) {
        set_errno_from_type(errno_, ERROR_NBR_ARG);
        return;
    }
    for (; str[*i] >= '0' && str[*i] <= '9'; i[0]++);
    if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\0' && str[*i] != ',')
        set_errno_from_type(errno_, ERROR_SYNTAXE);
}

void check_commande(char *str, int *h_cmd, errno_t *errno_)
{
    for (int i = 0; str[i]; i++) {
        if (errno_->value != NOT_ERROR)
            break;
        switch (str[i]){
        case '"':
            label_c(str, &i, errno_);
            break;
        case 'r':
            if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == ',')
                label_r(str, &i, errno_);
            break;
        case LABEL_CHAR:
            set_errno_from_type(errno_, check_commande_label(str, h_cmd, &i));
            break;
        case DIRECT_CHAR:
            set_errno_from_type(errno_, check_arg(str, &i));
            break;
        default:
            label_default(str, &i, h_cmd, errno_);
            break;
        }
    }
}

void lexer(errno_t *errno_, char **file)
{
    int tab[strlen_separator(COMMANDE, SEPARATOR)];
    int *hash_command = tab_hash_from_str(COMMANDE, SEPARATOR, tab);
    int nb_error = 0;

    for (int i = 0; file[i]; i++) {
        if (*file[i] != '\n' && *file[i])
            check_commande(file[i], hash_command, errno_);
        if (errno_->value != NOT_ERROR && *file[i]) {
            print_error("line %d", i);
            my_printf(" %s\n", errno_->errno_msg);
            my_printf("%s\n", file[i]);
            nb_error += 1;
            set_errno_from_type(errno_, NOT_ERROR);
        }
    }
    if (nb_error > 0)
        set_errno_from_type(errno_, ERROR_SYNTAXE);
    my_printf("number error (%d)\n", nb_error);
}