/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** compte le nombre de lettre dans la phrase
*/

int my_strlen(char const *str)
{
    int diff = 0;

    while (str[diff] != '\0') {
        diff++;
    }
    return (diff);
}