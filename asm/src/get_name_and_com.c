/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_name_and_com
*/

#include "asm.h"

static int check_end_line_name_and_com(char *str, int save)
{
    save++;
    for (; str[save] != '\0' && str[save] != '\n'; save++)
        if (str[save] != '\t' && str[save] != ' ' &&
            str[save] != '\0' && str[save] != '\n')
            return (84);
    return (0);
}

static int start_of_name_com(char *str, int *i, int *save)
{
    if (str[*i] != '\"')
        return (84);
    (*i)++;
    *save = *i;
    return (0);
}

static char *get_name_and_com(char *str, int *i, int size_max)
{
    char *name = NULL;
    int size = 0;
    int save = 0;
    int j = 0;

    if (start_of_name_com(str, i, &save) == 84)
        return (NULL);
    if (check_size(str, i, &size, size_max) == 84)
        return (NULL);
    name = malloc(sizeof(char) * (size + 1));
    if (name == NULL || (str[*i] == '\0' && check_end_of_line(str, i) == 0))
        return (NULL);
    for (; str[save] != '\"'; save++) {
        name[j] = str[save];
        j++;
    }
    name[j] = '\0';
    if (check_end_line_name_and_com(str, save) == 84)
        return (NULL);
    return (name);
}

char *get_name_and_com_champion(char *str, char *cmp, int size_max)
{
    int i = 0;

    if (skip_empty_space(str, &i) == 84)
        return (NULL);
    for (int j = 0; cmp[j] != '\0'; j++) {
        if (str[i] != cmp[j]) {
            return (NULL);
        }
        i++;
    }
    if (skip_empty_space(str, &i) == 84)
        return (NULL);
    return (get_name_and_com(str, &i, size_max));
}
