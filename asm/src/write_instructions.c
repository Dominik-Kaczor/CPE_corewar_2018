/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** write_instructions
*/

#include "asm.h"

int get_size_by_type(int type)
{
    if (type == 1)
        return (1);
    if (type == 2)
        return (4);
    if (type == 3 || type == 4)
        return (2);
    return (0);
}

int instruction_value(int *value, int type)
{
    if (type == 2)
        *value = (((*value>>24) & 0x000000ff) | ((*value>>8) & 0x0000ff00)
                | ((*value<<8) & 0x00ff0000) | ((*value<<24) & 0xff000000));
    if (type == 3 || type == 4)
        *value = (((*value & 0x00ff) << 8) | ((*value & 0xff00) >> 8));
    return (0);
}
