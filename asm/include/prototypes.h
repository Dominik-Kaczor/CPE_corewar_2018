/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** No description
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

bool my_strcmp(char *, char *);
bool invalid_char(char **);
bool my_strstr(char *, char *);
void fill_params(instr_t *, data_t *, op_t);
int check_register(char **, instr_t **, index_t);
bool check_name_comment(char *);
bool test(char *, char *);
int my_strlen(char *);
int input_processing(int, char **);
int get_champion(char **, char *);
int double_tab_len(char **);
int skip_empty_space(char *, int *);
int line_empty(char *);
int is_index(op_t, char **, instr_t **, index_t);
int get_size_by_type_two(int, int, int);
int count(data_t);
void my_printf(char *, ...);
void write_instruct(data_t, int);
void free_double_tab(char **);
void print_help(void);
int check_direct(op_t, char **, instr_t **, index_t);
void skip_comment_and_empty_line(char **, int *);
void my_memset(char *, int, size_t);
void write_header(data_t, int);
void my_putstr_err(char *);
char **get_file(char *);
char *get_path(char *);
char *my_strcat(char *, char *);
char **my_str_to_word_tab(char *, char);
char *my_strcpy(char *, char *);
char *my_strdup(char *);
char *get_name_and_com_champion(char *, char *, int);
char **str_to_word_array(char const *);
label_t *get_label(char **, int, unsigned int *);
int check_parameter_instruction(op_t, char *, data_t *, int);
int get_instruction(char **, int, data_t *);
int get_bytes_instruction(char **, int);
bool my_str_isnum(char const *);
int my_getnbr(char const *);
char **separate_params(char *);
index_t init_index(label_t *, int);
int is_label(char **, index_t, int, int);
char *remove_start_str(char *, int);
int my_labelcmp(char *, label_t *);
int is_direct(op_t, char **, instr_t **, index_t);
label_t *initialize_label_list(void);
int is_register(op_t, char **, instr_t **, index_t);
instr_t *initialize_instruction_list(void);
void replace_commment(char *c);
int check_end_of_line(char *str, int *i);
int check_size(char *str, int *i, int *size, int size_max);
char *stick_param_instr(char *str);
int get_size_by_type(int type);
int instruction_value(int *value, int type);

#endif /* !PROTOTYPES_H_ */

