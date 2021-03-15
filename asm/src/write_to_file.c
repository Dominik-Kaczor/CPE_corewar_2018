/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** test
*/

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "asm.h"

void binary_move(unsigned int *val)
{
    unsigned int revnbr = 0;
    unsigned int nbr = *val;

    for (int i = 3; i >= 0; i--) {
        ((char *)(&revnbr))[i] = ((char *)(&nbr))[0];
        nbr = nbr >> 8;
    }
    *val = revnbr;
}

void write_header(data_t data, int fd)
{
    header_t header;

    my_memset(header.comment, 0, COMMENT_LENGTH + 4);
    my_memset(header.prog_name, 0, PROG_NAME_LENGTH + 4);
    header.magic = COREWAR_EXEC_MAGIC;
    my_strcpy(header.comment, data.comment);
    my_strcpy(header.prog_name, data.name);
    header.prog_size = data.size_prog;
    binary_move(&header.magic);
    binary_move(&header.prog_size);
    write(fd, &header, sizeof(header_t));
}

void write_unit_instr(int i, instr_t *instr, int fd)
{
    for (; i != 1; i--)
        instr = instr->next;
    if (instr->code_instr != 0)
        write(fd, &(instr->code_instr), 1);
    if (instr->bin_param != 0)
        write(fd, &(instr->bin_param), 1);
    for (int j = 0; instr->param[j].bin != 0; j++) {
        instruction_value(&instr->param[j].value, instr->param[j].type);
        write(fd, &instr->param[j].value,
            get_size_by_type(instr->param[j].type));
    }
}

void write_instruct(data_t data, int fd)
{
    int i = count(data);

    while (i != 0) {
        write_unit_instr(i, data.data, fd);
        i--;
    }
}