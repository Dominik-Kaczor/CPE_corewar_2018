/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** malloc char *tab of the arena
*/

#include "corewar.h"

char *map_malloc(void)
{
    char *map = malloc(sizeof(char *) * (MEM_SIZE));

    if (map == NULL)
        return (NULL);
    for (int i = 0; i < MEM_SIZE; i++) {
        map[i] = 0;
    }
    return (map);
}
