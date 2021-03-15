/*
** EPITECH PROJECT, 2019
** cycle
** File description:
** cycle
*/

#include "corewar.h"

void display_live(champ_t *champ)
{
    while (champ) {
        my_printf("The player %d (%s) is alive.\n", champ->nb, champ->name);
        champ = champ->next;
    }
    return;
}

void cycle(champ_t *champ)
{
    int cycle = CYCLE_TO_DIE;

    for (int i = 0; cycle > 0; i++) {
        if (cycle == i) {
            display_live(champ);
            cycle -= CYCLE_DELTA;
            i = 0;
        }
    }
    return;
}
