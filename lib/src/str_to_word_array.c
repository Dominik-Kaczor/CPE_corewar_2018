/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(const char *);

static char **make_str(char const *str, int *i, int *j, char **dest)
{
    int s = 0;

    while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t') {
        dest[*j][s] = str[*i];
        (*i)++;
        s++;
    }
    dest[*j][s] = '\0';
    return (dest);
}

static char **malloc_str(char **dest, char const *str, int *i, int *j)
{
    int k = 0;
    int last_i = *i;

    while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t') {
        k++;
        (*i)++;
    }
    *i = last_i;
    if ((dest[*j] = malloc(sizeof(char) * (k + 1))) == NULL)
        return (NULL);
    dest = make_str(str, i, j, dest);
    (*j)++;
    return (dest);
}

static int nb_word(char const *str)
{
    int size = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (!((str[i] != '\0' && str[i] != ' ' && str[i] != '\t')) &&
            ((str[i] != '\0' && str[i + 1] != ' ' && str[i + 1] != '\t')))
            size++;
    return (size);
}

static int check_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
            return (1);
    return (0);
}

char **str_to_word_array(char const *str)
{
    int size = 1;
    char **dest = NULL;
    int j = 0;
    int len = my_strlen(str);

    if (check_str(str) == 0)
        return (NULL);
    if (*str == 0)
        return (dest);
    size = nb_word(str);
    if ((dest = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (NULL);
    for (int i = 0; (j == 0 && i < len) || (j < size
        && dest[j - 1] != NULL && i < len); i++) {
        if (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
            dest = malloc_str(dest, str, &i, &j);
    }
    dest[j] = NULL;
    return (dest);
}
