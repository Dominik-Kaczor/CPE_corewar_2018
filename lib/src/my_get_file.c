/*
** EPITECH PROJECT, 2019
** Get file
** File description:
** get_file
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int my_strlen(char *);
char *get_next_line(int);

char *my_strdup(char *s1)
{
    char *copy = malloc(sizeof(char) * (my_strlen(s1) + 1));

    if (copy == NULL)
        return (NULL);
    if (s1 == NULL)
        return (NULL);
    for (int i = 0; s1[i]; i++)
        copy[i] = s1[i];
    copy[my_strlen(s1)] = 0;
    return (copy);
}

int get_size(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i + 1);
}

char **my_realloc(char **tab, char *str)
{
    int a = get_size(tab);
    char **tmp = malloc(sizeof(char *) * (a+1));
    int i = 0;

    if (tmp == NULL)
        return (NULL);
    while (tab[i] != NULL) {
        tmp[i] = my_strdup(tab[i]);
        i++;
    }
    tmp[i] = my_strdup(str);
    tmp[i + 1] = 0;
    free(tab);
    return (tmp);
}

char **get_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;
    char **tab = malloc(sizeof(char *) * 100);

    tab[0] = get_next_line(fd);
    tab[1] = NULL;
    while ((str = get_next_line(fd)) != NULL)
        tab = my_realloc(tab, str);
    free(str);
    return (tab);
}