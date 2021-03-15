/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_label
*/

#include "asm.h"

label_t *initialize_label_list(void)
{
    label_t *label = malloc(sizeof(label_t));

    if (label == NULL)
        return (NULL);
    label->label = NULL;
    label->pos = 0;
    label->next = NULL;
    return (label);
}

static void add_label_into_list(label_t **label, char *name, int nb_bytes)
{
    label_t *element = malloc(sizeof(label_t));

    if (element == NULL)
        exit(84);
    element->label = my_strdup(name);
    element->label[my_strlen(element->label) - 1] = '\0';
    element->pos = nb_bytes;
    element->next = *label;
    *label = element;
}

static int cmpchar(char str, char *cmp)
{
    for (int i = 0; cmp[i] != '\0'; i++)
        if (cmp[i] == str)
            return (1);
    return (0);
}

static void check_label(char *str, label_t *label)
{
    int i = 0;

    for (; str[i + 1] != '\0'; i++)
        if (cmpchar(str[i], LABEL_CHARS) == 0)
            exit(84);
    str[i] = '\0';
    while (label->next != NULL) {
        if (my_strcmp(str, label->label) == 1)
            exit(84);
        label = label->next;
    }
    str[i] = LABEL_CHAR;
}

label_t *get_label(char **str, int index, unsigned int *size_prog)
{
    label_t *label = initialize_label_list();
    char **arg = NULL;
    int nb_bytes = 0;
    int len = 0;

    for (; str[index] != NULL; index++) {
        str[index] = stick_param_instr(str[index]);
        arg = str_to_word_array(str[index]);
        len = double_tab_len(arg);
        if ((len == 1 || len == 3) &&
            (arg[0][my_strlen(arg[0]) - 1] == LABEL_CHAR)) {
            check_label(arg[0], label);
            add_label_into_list(&label, arg[0], nb_bytes);
        }
        nb_bytes += get_bytes_instruction(arg, len);
        free_double_tab(arg);
    }
    *size_prog = nb_bytes;
    return (label);
}
