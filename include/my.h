/*
** EPITECH PROJECT, 2019
** my_import
** File description:
** task02 day09
*/

#ifndef MY_IMPORT
#define MY_IMPORT

void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
void my_put_nbr(long long int nb);
void my_putstr(char const *str);
void my_printf_S(char *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
char *my_strncpy(char *dest, char const *src, int n);
char **split(char *str, char split);
int count_array(char **array);
int my_getnbr(char *str);
int is_alpha(char c);
char *my_revstr(char *src);
char *number_to_byte(int number);
char *my_calloc(char *str, int new_size);
#endif
