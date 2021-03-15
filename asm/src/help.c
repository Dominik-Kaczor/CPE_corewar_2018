/*
** EPITECH PROJECT, 2019
** Corewar / ASM
** File description:
** help
*/

#include "asm.h"

void replace_commment(char *c)
{
    if (*c == COMMENT_CHAR)
        *c = '\0';
}

void print_help(void)
{
    my_printf("USAGE\n\t./asm file_name[.s]\n\nDESCRIPTION\n\tfile_name\t"
    "file in assembly language to be converted into file_name.cor, an\n"
    "\t\t\texecutable in the Virtual Machine.\n");
}