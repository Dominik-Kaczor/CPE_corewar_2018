/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** stick_params
*/

#include "asm.h"

static int check_if_label(char *str, int *i)
{
    for (;str[*i] != '\0' && str[*i] != '\n'; (*i)++) {
        if (str[*i] == ':')
            return (1);
        if (str[*i] == '\t' || str[*i] == ' ')
            return (0);
    }
    return (0);
}

static void give_status(char *str, int *i, int *status, int *status_label)
{
    if (check_if_label(str, i) == 1 && *status_label == 0)
        *status_label = 1;
    else
        *status = 1;
}

static char *stick_params(char *str, int *i)
{
    int save = *i;

    for (; str[*i] != '\0' && str[*i] != '\n'; (*i)++)
        if (str[*i] != '\t' && str[*i] != ' ') {
            str[save] = str[*i];
            save++;
        }
    str[save] = '\0';
    return (str);
}

char *stick_param_instr(char *str)
{
    int i = 0;
    int status = 0;
    int status_label = 0;

    for (; status == 0 && str[i] != '\0' && str[i] != '\n'; i++)
        if (str[i] != '\t' && str[i] != ' ')
            give_status(str, &i, &status, &status_label);
    for (; str[i] != '\0' && str[i] != '\n' &&
        str[i] != '\t' && str[i] != ' '; i++);
    return (stick_params(str, &i));
}