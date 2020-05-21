/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** change la valeur
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *b;
    *b = *a;
    *a = c;
}
