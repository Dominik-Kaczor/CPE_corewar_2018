/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** No description
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "op.h"

typedef struct label_s
{
    char *label;
    int pos;
    struct label_s *next;
} label_t;


typedef struct index_s
{
    int bytes;
    label_t *label;
    int i;
} index_t;

typedef struct param_s
{
    int type;
    int bin;
    int value;
} param_t;

typedef struct instr_s
{
    int bin_param;
    int code_instr;
    param_t param[MAX_ARGS_NUMBER];
    struct instr_s *next;
} instr_t;

typedef struct header_s {
    unsigned int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    unsigned int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct data_s
{
    char *name;
    char *comment;
    unsigned int size_prog;
    instr_t *data;
    label_t *label;
} data_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

extern op_t op_tab[];

#endif
