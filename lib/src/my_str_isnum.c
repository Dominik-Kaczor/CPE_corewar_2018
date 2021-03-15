/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Write a function that returns 1 if the string passed as parameter only
** contains digits and 0 otherwise.
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    int i = 0;

    if (str == (void *) 0)
        return (false);
    if (str[i] == '-')
        i++;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (false);
    }
    return (true);
}
