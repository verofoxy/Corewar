/*
** EPITECH PROJECT, 2019
** my_power_rec
** File description:
** display the power
*/

int my_compute_power_rec(int nb, int p)
{
    int result;
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (nb * my_compute_power_rec(nb, p - 1));
}
