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

int count_array(char **array)
{
    int floor = 0;

    for (; array[floor]; floor++);
    return floor;
}

int number(char *str)
{
    int a = 0;
    long nb = 0;
    int	signe = 1;

    while (str[a] < '0' || str[a] > '9') {
        if (str[a] == '-')
            signe = signe * -1;
        if (str[a] == '\n' || str[a] == '\0') break;
        a++;
    }
    while (str[a] <= '9' && str[a] >= '0') {
        nb = (nb * 10) + (str[a] - '0');
        if (str[a] == '\n' || str[a] == '\0') break;
        a++;
    }
    str = str + a;
    if (nb > 2147483647 && nb < -2147483648) return (0);
    nb = nb * signe;
    return (nb);
}