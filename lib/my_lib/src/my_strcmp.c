/*
** EPITECH PROJECT, 2020
** generator
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int m_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (s1[0] != s2[0] || my_strlen(s1) != my_strlen(s2))
        return 1;
    for (; s1[i] &&  s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
