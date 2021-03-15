/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** vm's arguments check
*/

#include "corewar.h"

int args_check(int ac, char **av, char **env)
{
    int i = 1;

    if (env == NULL) {
        write(2, "Error on env!\n", 14);
        return (84);
    }
    while (i < ac) {
        if (!my_strstr(av[i], ".cor")) {
            write(2, "Error: args have to be .cor!\n", 29);
            return (84);
        }
        i++;
    }
    return (0);
}
