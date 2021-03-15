/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** No description
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "op.h"

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

typedef struct cont_s {
    struct champ_s *next;
}cont_t;

typedef struct champ_s {
    char *m_nb;
    char *name;
    char *comment;
    int pos;
    int nb;
    int *reg;
    int carry;
    int addres;
    char *function;
    int size;
    struct champ_s *next;
} champ_t;

extern op_t op_tab[];

#endif
