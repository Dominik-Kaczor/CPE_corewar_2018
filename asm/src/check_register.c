/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_register
*/

#include "asm.h"

index_t init_index(label_t *label, int bytes)
{
    index_t index;

    index.bytes = bytes;
    index.i = 0;
    index.label = label;
    return (index);
}

int check_register(char **param, instr_t **elem, index_t index)
{
    if (param[index.i][0] != '\0' && param[index.i][0] == 'r') {
        param[index.i][0] = '0';
        if (my_str_isnum(param[index.i]) == 0)
            return (84);
        (*elem)->param[index.i].value = my_getnbr(param[index.i]);
        (*elem)->param[index.i].bin = 1;
        (*elem)->param[index.i].type = 1;
        if ((*elem)->param[index.i].value < 1
            || (*elem)->param[index.i].value > REG_NUMBER)
            return (84);
        return (1);
    }
    return (0);
}

int is_register(op_t op, char **param, instr_t **elem, index_t index)
{
    int status = 0;

    if (op.type[index.i] == 1 || op.type[index.i] == 3
        || op.type[index.i] == 5 || op.type[index.i] == 7) {
        status = check_register(param, elem, index);
        if (status == 84) {
            my_putstr_err("Bad register\n");
            exit(84);
        }
        if (status == 1)
            return (1);
    }
    return (0);
}
