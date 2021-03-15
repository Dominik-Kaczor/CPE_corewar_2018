/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main for the virtual machine
*/

#include "corewar.h"

int main(int ac, char **av, char **env)
{
    cont_t *cont = malloc(sizeof(cont_t));
    champ_t *champ = malloc(sizeof(champ_t));

    if (ac < 2)
        return (84);
    if (args_check(ac, av, env) == 84)
        return (84);
    cont->next = champ;
    for (int i = 1; i < ac; i++) {
        take_infos(champ, av[i]);
        if (i + 1 == ac)
            champ->next = NULL;
        else
            champ->next = malloc(sizeof(champ_t));
        champ = champ->next;
    }
    return (corewar(cont->next));
}
