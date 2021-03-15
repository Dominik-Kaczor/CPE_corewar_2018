/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** print a char given as parameter
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_p(char *c)
{
    write(1, &c, 1);
}
