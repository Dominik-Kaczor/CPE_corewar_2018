/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_name_com
*/

#include "asm.h"

int check_end_of_line(char *str, int *i)
{
    (*i)++;
    for (; str[*i] != '\0' && str[*i] != COMMENT_CHAR
        && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n');
        (*i)++);
    if (str[*i] != '\0')
        return (EXIT_ERROR);
    return (EXIT_OK);
}

int check_size(char *str, int *i, int *size, int size_max)
{
    for (; str[*i] != '\0' && str[*i] != '\"'; (*size)++)
        (*i)++;
    if (*size > size_max) {
        my_putstr_err("Name or comment too long.\n");
        return (84);
    }
    return (0);
}