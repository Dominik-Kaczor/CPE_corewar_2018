/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** virtual machine management
*/

#include "corewar.h"

int space_champ(champ_t *champ)
{
    int size = 0;
    int nb_champ = 0;

    while (champ) {
        nb_champ++;
        size += champ->size;
        champ = champ->next;
    }
    if (nb_champ == 1)
        return (0);
    else
        return (size);
}

char *pos_arena(champ_t *champ, char *arena, int pos)
{
    for (int b = 0; b < champ->size; b++)
        arena[pos + b] = champ->function[b];
    return (arena);
}

char *add_arena(champ_t *champ, char *arena)
{
    int dis = space_champ(champ);
    int size = 0;

    for (int i = 0; champ; i++) {
        champ->addres = (dis * i + size);
        arena = pos_arena(champ, arena, champ->addres);
        size += champ->size;
        champ = champ->next;
    }
    return (arena);
}

void add_number(champ_t *champ)
{
    for (int i = 1; champ ; i++) {
        champ->nb = i;
        champ = champ->next;
    }
    return;
}

int corewar(champ_t *champ)
{
    char *map = map_malloc();

    if (map == NULL) {
        write(2, "Error: No more empty place!\n", 28);
        return (84);
    }
    map = add_arena(champ, map);
    add_number(champ);
    cycle(champ);
    my_printf("The player %d (%s) has won.\n", champ->nb, champ->name);
    return (0);
}
