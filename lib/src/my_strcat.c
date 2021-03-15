/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concat two strings
*/

#include <stdlib.h>

int my_strlen(const char *);

char *my_strcat(char *one, char *two)
{
    char *final = malloc(sizeof(char) * (my_strlen(one) + my_strlen(two) + 1));
    int i = 0;
    int k = 0;

    for (; one[i]; i++)
        final[i] = one[i];
    for (; two[k]; i++, k++)
        final[i] = two[k];
    final[i] = '\0';
    return (final);
}
