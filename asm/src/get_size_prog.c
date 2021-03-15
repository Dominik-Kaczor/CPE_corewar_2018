/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_size_prog
*/

#include "asm.h"

static int get_instruction_bytes(int *status, int i, char *arg)
{
    if (my_strcmp(op_tab[i].mnemonique, arg) == 1) {
        *status = i;
        if (my_strcmp(op_tab[i].mnemonique, "live") == 1
            || my_strcmp(op_tab[i].mnemonique, "zjmp") == 1
            || my_strcmp(op_tab[i].mnemonique, "fork") == 1
            || my_strcmp(op_tab[i].mnemonique, "lfork") == 1)
            return (1);
        return (2);
    }
    return (0);
}

static int check_bytes_direct(int *status)
{
    if (my_strcmp(op_tab[*status].mnemonique, "sti") == 1
        || my_strcmp(op_tab[*status].mnemonique, "fork") == 1
        || my_strcmp(op_tab[*status].mnemonique, "lfork") == 1
        || my_strcmp(op_tab[*status].mnemonique, "ldi") == 1
        || my_strcmp(op_tab[*status].mnemonique, "zjmp") == 1)
        return (2);
    return (4);
}

static int get_bytes_arg(char *param, int *status)
{
    char **arg = separate_params(param);
    int bytes = 0;

    if (arg == NULL || double_tab_len(arg) > 4)
        return (0);
    for (int i = 0; arg[i] != 0; i++) {
        if (arg[i][0] != '\0' && arg[i][0] == 'r')
            bytes++;
        else if (arg[i][0] != '\0' && arg[i][0] == DIRECT_CHAR)
            bytes += check_bytes_direct(status);
        else
            bytes += 2;
    }
    return (bytes);
}

static int count_bytes(char **arg, int len)
{
    int status = -1;
    int nb_bytes = 0;

    for (int i = 0; status == -1 && op_tab[i].mnemonique != NULL; i++)
        nb_bytes = get_instruction_bytes(&status, i, arg[len]);
    nb_bytes += get_bytes_arg(arg[len + 1], &status);
    if (status == -1)
        exit(84);
    return (nb_bytes);
}

int get_bytes_instruction(char **arg, int len)
{
    if (len == 0 || len == 1)
        return (0);
    if (len > 3)
        exit(84);
    if (len == 3)
        return (count_bytes(arg, 1));
    else
        return (count_bytes(arg, 0));
    return (0);
}