/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** useful_fonctions_two
*/

#include "asm.h"

char *remove_start_str(char *str, int size)
{
    char *cpy = my_strdup(str);
    int i = 0;

    for (; size < my_strlen(str) && str[i] != '\0'; i++) {
        str[i] = cpy[size];
        size++;
    }
    for (; cpy[i] != '\0'; i++)
        str[i] = '\0';
    free(cpy);
    return (str);
}

int my_labelcmp(char *label, label_t *list)
{
    while (list->next != NULL) {
        if (my_strcmp(label, list->label) == 1)
            return (list->pos);
        list = list->next;
    }
    return (-2);
}