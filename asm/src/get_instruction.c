/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_instruction
*/

#include "asm.h"

instr_t *initialize_instruction_list(void)
{
    instr_t *data = malloc(sizeof(instr_t));

    if (data == NULL)
        return (NULL);
    data->bin_param = 0;
    data->code_instr = 0;
    for (int i = 0; i < 4; i++) {
        data->param[i].bin = 0;
        data->param[i].type = 0;
        data->param[i].value = 0;
    }
    data->next = NULL;
    return (data);
}

static void get_information_instruction(op_t op, char *str,
        data_t *data, int bytes)
{
    int nb_arg = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == SEPARATOR_CHAR)
            nb_arg++;
    if (nb_arg != op.nbr_args - 1)
        exit(84);
    if (check_parameter_instruction(op, str, data, bytes) == -1)
        exit(84);
}

static void find_instruction(char **arg,
        data_t *data, int bytes, int len)
{
    int status = 0;

    if (len == 3)
        len = 1;
    else
        len = 0;
    for (int i = 0; status == 0 && op_tab[i].mnemonique != NULL; i++)
        if (my_strcmp(op_tab[i].mnemonique, arg[len]) == 1) {
            get_information_instruction(op_tab[i], arg[len + 1], data, bytes);
            status = 1;
        }
    if (status == 0)
        exit(84);
}

int get_instruction(char **str, int index, data_t *data)
{
    char **arg = NULL;
    int len = 0;
    int bytes = 0;

    data->data = initialize_instruction_list();
    for (; str[index] != NULL; index++) {
        str[index] = stick_param_instr(str[index]);
        arg = str_to_word_array(str[index]);
        len = double_tab_len(arg);
        if (len > 3 || (len == 1 && arg[0][my_strlen(arg[0]) - 1] !=
            LABEL_CHAR) || (len == 3 && arg[0][my_strlen(arg[0]) - 1] !=
            LABEL_CHAR))
            return (84);
        if (len == 2 || len == 3)
            find_instruction(arg, data, bytes, len);
        bytes += get_bytes_instruction(arg, len);
        free_double_tab(arg);
    }
    return (0);
}