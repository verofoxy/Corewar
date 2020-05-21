/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copie la string dans une autre variable par rapport a la longeur de n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int letter = 0;
    int i = 0;

    while (i != n) {
        dest[letter] = src[letter];
        letter++;
        i++;
    }
    return (dest);
}
