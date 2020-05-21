/*
** EPITECH PROJECT, 2019
** my_strcpy task01
** File description:
** print in the string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
