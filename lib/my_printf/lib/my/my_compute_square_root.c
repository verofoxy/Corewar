/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** display
*/

int my_compute_square_root(int nb)
{
    int sq;
    if (nb < 1)
        return (0);
    sq = 0;
    while (sq * sq != nb){
        if (sq > nb)
            return (0);
        sq++;
    }
    return (sq);
}
