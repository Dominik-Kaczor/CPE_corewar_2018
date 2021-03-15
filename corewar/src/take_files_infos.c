/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** functions used to get champions infos
*/

#include "corewar.h"

void get_function(unsigned char *buffer, champ_t *champ)
{
    int i = 0;

    champ->function = malloc(sizeof(unsigned char) * (champ->size + 1));
    champ->function[champ->size] = '\0';
    while (i < champ->size) {
        champ->function[i] = buffer[2192 + i];
        i++;
    }
}

void take_infos(champ_t *champ, char *filepath)
{
    unsigned char buffer[MEM_SIZE];
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "Error: no such file\n", 20);
        exit (84);
    }
    read(fd, &buffer, sizeof(buffer));
    get_magique_nb(buffer, champ);
    get_name(buffer, champ);
    get_size(buffer, champ);
    get_comment(buffer, champ);
    get_function(buffer, champ);
}
