/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** useful_fonctions
*/

#include <stdlib.h>
#include "asm.h"

void free_double_tab(char **str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

int double_tab_len(char **str)
{
    int i = 0;

    if (str == NULL)
        return (i);
    for (; str[i] != NULL; i++);
    return (i);
}

int skip_empty_space(char *str, int *i)
{
    for (; str[*i] != '\0' && (str[*i] == ' ' || str[*i] == '\t'); (*i)++);
    if (str[*i] == '\0')
        return (EXIT_ERROR);
    if (str[*i] == COMMENT_CHAR) {
        (*i)++;
        return (skip_empty_space(str, i));
    }
    return (EXIT_OK);
}

int line_empty(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == COMMENT_CHAR)
            return (EXIT_NOK);
        else if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
            return (EXIT_OK);
    return (EXIT_NOK);
}

void skip_comment_and_empty_line(char **str, int *i)
{
    while (str[*i][0] == '\n' || str[*i][0] == COMMENT_CHAR
            || line_empty(str[*i]) == 1)
        (*i)++;
}