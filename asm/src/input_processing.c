/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** input_processing
*/

#include <unistd.h>
#include "asm.h"

static bool check_help(char **av)
{
    if (my_strcmp(av[1], "-h")) {
        print_help();
        return (true);
    }
    return (false);
}

static bool check_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        my_putstr_err("No such file\n");
        return (true);
    }
    close(fd);
    return (false);
}

static bool check_extension(char **av)
{
    if (my_strlen(av[1]) > 2 && (av[1][my_strlen(av[1]) - 2] != '.' ||
        av[1][my_strlen(av[1]) - 1] != 's'))
        return (true);
    return (false);
}

int rm_comment(char **file, char *final_path)
{
    for (int i = 0; file[i] != NULL; i++)
        for (int j = 0; file[i][j] != '\0'; j++)
            replace_commment(&file[i][j]);
    if (invalid_char(file)) {
        my_putstr_err("Invalid char\n");
        return (EXIT_ERROR);
    }
    return (get_champion(file, final_path));
}

int input_processing(int ac, char **av)
{
    char **input_file = NULL;
    char *final_path = NULL;

    if (ac != 2)
        return (EXIT_ERROR);
    if (ac == 2) {
        if (check_help(av))
            return (EXIT_OK);
        if (check_extension(av))
            return (EXIT_ERROR);
        if (!check_file(av[1])) {
            input_file = get_file(av[1]);
            final_path = get_path(av[1]);
        } else
            return (EXIT_ERROR);
    }
    return (rm_comment(input_file, final_path));
}
