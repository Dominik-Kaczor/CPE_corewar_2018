/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** functions used to get the algo name
*/

#include "corewar.h"

void get_name(unsigned char *buffer, champ_t *champ)
{
    int size = 0;

    while (buffer[champ->pos] != 0) {
        size++;
        champ->pos++;
    }
    champ->pos -= size;
    champ->name = malloc(sizeof(char) * (size + 1));
    champ->name[size] = '\0';
    size = 0;
    while (buffer[champ->pos] != 0) {
        champ->name[size] = buffer[champ->pos];
        champ->pos++;
        size++;
    }
}

void get_comment(unsigned char *buffer, champ_t *champ)
{
    int size = 0;

    while (buffer[champ->pos] != 0) {
        size++;
        champ->pos++;
    }
    champ->pos -= size;
    champ->comment = malloc(sizeof(char) * (size + 1));
    champ->comment[size] = '\0';
    size = 0;
    while (buffer[champ->pos] != 0) {
        champ->comment[size] = buffer[champ->pos];
        champ->pos++;
        size++;
    }
}
