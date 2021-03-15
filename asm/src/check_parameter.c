/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_parameter
*/

#include "asm.h"

static int check_indirect(char **param, instr_t **elem, index_t index)
{
    if (my_str_isnum(param[index.i]) == 0)
        return (84);
    (*elem)->param[index.i].value = my_getnbr(param[index.i]);
    (*elem)->param[index.i].bin = 3;
    (*elem)->param[index.i].type = 3;
    return (1);
}

static int is_indirect(op_t op, char **param, instr_t **elem, index_t index)
{
    int status = 0;

    if (op.type[index.i] == 4 || op.type[index.i] == 5
        || op.type[index.i] == 6 || op.type[index.i] == 7) {
        status = check_indirect(param, elem, index);
        if (status == 84) {
            my_putstr_err("Bad indirect\n");
            exit(84);
        }
        if (status == 1)
            return (1);
    }
    return (0);
}

void fill_params(instr_t *elem, data_t *data, op_t op)
{
    if (!(my_strcmp(op.mnemonique, "live") == 1
        || my_strcmp(op.mnemonique, "zjmp") == 1
        || my_strcmp(op.mnemonique, "fork") == 1
        || my_strcmp(op.mnemonique, "lfork") == 1))
        elem->bin_param = (elem->param[0].bin * 64) +
                        (elem->param[1].bin * 16) +
                        (elem->param[2].bin * 4);
    elem->code_instr = op.code;
    elem->next = data->data;
    data->data = elem;
}

int check_parameter_instruction(op_t op, char *str,
        data_t *data, int bytes)
{
    char **arg = separate_params(str);
    int status = 0;
    instr_t *element = initialize_instruction_list();
    index_t index = init_index(data->label, bytes);

    if (arg == NULL || element == NULL)
        return (-1);
    for (int i = 0; i < op.nbr_args; i++) {
        index.i = i;
        if (is_register(op, arg, &element, index) == 1
            || is_direct(op, arg, &element, index) == 1
            || is_indirect(op, arg, &element, index) == 1)
            status = 1;
        if (status == 0)
            return (-1);
        status = 0;
    }
    free_double_tab(arg);
    fill_params(element, data, op);
    return (1);
}
