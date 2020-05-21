/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** hash.c
*/

int strlen_separator(char *str, char separator)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        count += (str[i] == separator) ? (1) : (0);
    return (count);
}

int *tab_hash_from_str(char *str, char separator, int *tab)
{
    int j = 0;

    tab[0] = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != separator)
            tab[j] += (int)str[i];
        else
            tab[++j] = 0;
    return (tab);
}