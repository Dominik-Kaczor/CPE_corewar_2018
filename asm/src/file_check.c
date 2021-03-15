/*
** EPITECH PROJECT, 2019
** corewar, asm
** File description:
** check invalid chars on the file
*/

#include "asm.h"

bool check_name_comment(char *line)
{
    if (my_strstr(line, NAME_CMD_STRING))
        return (false);
    else if (my_strstr(line, COMMENT_CMD_STRING))
        return (false);
    return (true);
}

static bool check_char(char c)
{
    if (c == LABEL_CHAR || c == DIRECT_CHAR || c == SEPARATOR_CHAR || c == '.'
        || c == '_' || c == ' ' || c == '\t' || c == '-')
        return (false);
    if (c >= 'a' && c <= 'z')
        return (false);
    if (c >= '0' && c <= '9')
        return (false);
    if (c == COMMENT_CHAR)
        c = '\0';
    return (true);
}

static bool check_line(char *line)
{
    int i = 0;

    while (line[i] && line[i] != COMMENT_CHAR) {
        if (line[i] == '.')
            return (check_name_comment(line));
        if (check_char(line[i]))
            return (true);
        i++;
    }
    return (false);
}

bool invalid_char(char **file)
{
    for (int i = 0; file[i]; i++)
        if (check_line(file[i]))
            return (true);
    return (false);
}