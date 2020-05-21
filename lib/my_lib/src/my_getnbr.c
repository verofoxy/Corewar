/*
** EPITECH PROJECT, 2019
** my getnbr
** File description:
** rtghjk
*/

int is_num(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}

int my_getnbr(char *str)
{
    int result = 0, i = 0, is_neg = 1;

    while (str[i] && is_num(str[i]) == 0) {
        if (str[i] == '-')
            is_neg *= -1;
        i++;
    }
    while (str[i] && is_num(str[i]) == 1) {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return result * is_neg;
}
