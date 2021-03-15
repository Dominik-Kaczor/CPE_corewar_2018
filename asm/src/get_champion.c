/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_champion
*/

#include "asm.h"
#include <unistd.h>

int open_file(char *path)
{
    int fd = 0;

    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd == -1)
        exit(EXIT_ERROR);
    return (fd);
}

static int get_name_and_comment(data_t *data, int *i, char **str)
{
    if (str == NULL || str[0] == NULL)
        return (EXIT_ERROR);
    skip_comment_and_empty_line(str, i);
    data->name = get_name_and_com_champion(str[*i],
            NAME_CMD_STRING, PROG_NAME_LENGTH);
    if (data->name == NULL)
        return (EXIT_ERROR);
    (*i)++;
    skip_comment_and_empty_line(str, i);
    data->comment = get_name_and_com_champion(str[*i],
            COMMENT_CMD_STRING, COMMENT_LENGTH);
    if (data->comment == NULL)
        return (EXIT_ERROR);
    (*i)++;
    return (EXIT_OK);
}

int count(data_t data)
{
    instr_t *current = data.data;
    int i = 0;

    while (current != NULL) {
        i++;
        current = current->next;
    }
    return (i - 1);
}

int get_champion(char **str, char *final_path)
{
    data_t data;
    int i = 0;
    int fd = 0;

    if (get_name_and_comment(&data, &i, str) == EXIT_ERROR)
        return (EXIT_ERROR);
    data.label = get_label(str, i, &data.size_prog);
    fd = open_file(final_path);
    if (get_instruction(str, i, &data) == 84)
        return (EXIT_ERROR);
    write_header(data, fd);
    write_instruct(data, fd);
    return (EXIT_OK);
}
