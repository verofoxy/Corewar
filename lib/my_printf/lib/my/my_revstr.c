/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i, compteur = 0;
    i = my_strlen(str) - 1;
    while (i != 0) {
        str[compteur] = str[i];
        i--;
        compteur++;
    }
    return (str);
}
