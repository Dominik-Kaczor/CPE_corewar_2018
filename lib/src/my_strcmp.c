/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

#include <stdbool.h>
#include <stdlib.h>

int my_strlen(char const *);

bool my_strcmp(char const *s1, char const *s2)
{
    int s1_len = 0;
    int s2_len = 0;

    if (s1 == NULL)
        return (false);
    if (s2 == NULL)
        return (false);
    s1_len = my_strlen(s1);
    s2_len = my_strlen(s2);
    if (s1_len != s2_len)
        return (false);
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (false);
    }
    return (true);
}