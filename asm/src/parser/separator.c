/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** separator.c
*/

char detect_type(char str, char st)
{
    if (str == ',' && st != ' ')
        str = ' ';
    return str;
}

void separator(char **command)
{
    for (int i = 0; command[i]; i++) {
        for (int letter = 0; command[i][letter]; letter++) {
            command[i][letter] = detect_type(command[i][letter], command[i][letter++]);
        }
    }
}