/*
** EPITECH PROJECT, 2019
** my_get_nbr
** File description:
** display the number and stops when it encounters a letter
*/

int my_getnbr(char const *str)
{
    int i, n, r = 0;
    int neg = 1;

    while (str[i] != '\0') {

        if ( str[i] == '-') {
            str = str + -1;
        }
    }

    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    r = n * neg;
    return (r);
}
