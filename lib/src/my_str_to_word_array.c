/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *);

static int count_words(char *str, char separator)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == separator)
            count += 1;
        i += 1;
    }
    return (count + 1);
}

static int skip_space(char *str, int i)
{
    while (str[i] == '\t' || str[i] == ' ')
        i += 1;
    return (i);
}

static char **check_malloc(char **tab)
{
    if (tab == NULL)
        return (NULL);
    tab[0] = malloc(sizeof(char) * 50);
    return (tab);
}

char **my_str_to_word_tab(char *str, char separator)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (count_words(str, separator) + 1));

    if (check_malloc(tab) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == separator) {
            tab[j][k] = '\0';
            k = 0;
            j += 1;
            tab[j] = malloc(sizeof(char) * 10 * (my_strlen(str) + 1));
            i += 1;
        }
        tab[j][k++] = str[i++];
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}
