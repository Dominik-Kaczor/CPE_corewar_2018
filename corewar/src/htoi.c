/*
** EPITECH PROJECT, 2019
** htoi.c
** File description:
** htoi
*/

#include "corewar.h"

int htoi(char *str)
{
    int nb = 0;
    int base = 1;
    int len = my_strlen(str) - 1;

    for (int i = len; i >= 0; i--) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb += (str[i] - 48) * base;
            base = base * 16;
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            nb += (str[i] - 87) * base;
            base = base * 16;
        }
    }
    return (nb);
}
