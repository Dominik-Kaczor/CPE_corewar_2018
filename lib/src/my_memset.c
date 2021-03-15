/*
** EPITECH PROJECT, 2019
** memset
** File description:
** my_memset
*/

#include <stdlib.h>

void my_memset(char *str, int c, size_t size)
{
    for (size_t i = 0; i != size; i++)
        str[i] = c;
    return;
}