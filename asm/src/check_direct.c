/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_direct
*/

#include "asm.h"

int is_label(char **param, index_t index, int i, int loc)
{
    int label_pos = 0;

    if (param[index.i][i] != '\0' && param[index.i][i] == LABEL_CHAR) {
        param[index.i] = remove_start_str(param[index.i], loc);
        label_pos = my_labelcmp(param[index.i], index.label);
        if (label_pos == -2)
            return (-2);
        return (label_pos);
    }
    return (-1);
}

int is_index(op_t op, char **param, instr_t **elem, index_t index)
{
    int pos_label = -1;

    if (my_strcmp(op.mnemonique, "ldi") == 1 ||
        my_strcmp(op.mnemonique, "zjmp") == 1 ||
        my_strcmp(op.mnemonique, "fork") == 1 ||
        my_strcmp(op.mnemonique, "lfork") == 1 ||
        my_strcmp(op.mnemonique, "sti") == 1) {
        pos_label = is_label(param, index, 1, 2);
        if (pos_label == -2)
            return (84);
        if (pos_label != -1)
            (*elem)->param[index.i].value = pos_label - index.bytes;
        else
            (*elem)->param[index.i].value = my_getnbr(param[index.i]);
        (*elem)->param[index.i].bin = 2;
        (*elem)->param[index.i].type = 4;
        return (1);
    }
    (*elem)->param[index.i].type = 2;
    return (0);
}

int check_direct(op_t op, char **param, instr_t **elem, index_t index)
{
    int status = 0;

    if (param[index.i][0] != '\0' && param[index.i][0] == DIRECT_CHAR) {
        param[index.i][0] = '0';
        status = is_index(op, param, elem, index);
        if (status == 84)
            return (84);
        if (status == 1)
            return (1);
        if (my_str_isnum(param[index.i]) == 0)
            return (84);
        (*elem)->param[index.i].value = my_getnbr(param[index.i]);
        (*elem)->param[index.i].bin = 2;
        return (1);
    }
    return (0);
}

int is_direct(op_t op, char **param, instr_t **elem, index_t index)
{
    int status = 0;

    if (op.type[index.i] == 2 || op.type[index.i] == 3
        || op.type[index.i] == 6 || op.type[index.i] == 7) {
        status = check_direct(op, param, elem, index);
        if (status == 84) {
            my_putstr_err("Bad direct\n");
            exit(84);
        }
        if (status == 1)
            return (1);
    }
    return (0);
}
