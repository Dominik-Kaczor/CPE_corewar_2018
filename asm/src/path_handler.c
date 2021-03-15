/*
** EPITECH PROJECT, 2019
** Corewar / ASM
** File description:
** path_handler
*/

#include "asm.h"

char *get_path(char *filepath)
{
    int len = my_strlen(filepath);

    if (filepath[len - 1] == 's' && filepath[len - 2] == '.') {
        filepath[len - 2] = '\0';
        return (my_strcat(filepath, ".cor"));
    }
    return (my_strcat(filepath, ".cor"));
}