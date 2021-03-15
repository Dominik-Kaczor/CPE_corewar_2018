/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** Write a function that returns 1 if the string passed as parameter only
** contains alphabetical characters and 0 if the string contains another type of
** character.
*/

#include <stdbool.h>

bool my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
            return (false);
        else
            i++;
    }
    return (true);
}