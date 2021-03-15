/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print a string of char on the standard output
*/

#include <unistd.h>

int my_strlen(char const *);

void my_putchar(char);

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putstr_term_key(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '\E')
            write(1, "^E", 2);
        else
            my_putchar(str[i]);
        i++;
    }
}

void my_putstr_err(char *str)
{
    write(2, str, my_strlen(str));
}