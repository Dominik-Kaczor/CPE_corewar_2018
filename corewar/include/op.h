/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op
*/

#ifndef _OP_H_
#define _OP_H_

typedef char args_type_t;

#define MEM_SIZE (6*1024)
#define IDX_MOD 512
#define MAX_ARGS_NUMBER 4
#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','
#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"
#define REG_NUMBER 16

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE DIR_SIZE

#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#define STR_MAGIC "0xea83f3"
#define COREWAR_EXEC_MAGIC 0xea83f3

#endif
