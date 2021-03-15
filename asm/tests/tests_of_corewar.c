/*
** EPITECH PROJECT, 2019
** Tests generic
** File description:
** This set of tests test the program function by function
*/
#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(input_processing, error_args, .init = redirect_all_std)
{
    int ac = 3;
    char *av[] = { "salut", "salut", "salut" };
    int dest = input_processing(ac, av);

    cr_assert_eq(dest, 84);
}

Test(is_direct, bad_direct, .init = redirect_all_std)
{
    op_t op = op_tab[0];
    char **param = separate_params("salut les amis");
    instr_t *elem = initialize_instruction_list();
    index_t index;
    int dest;

    dest = is_direct(op, param, &elem, index);
    cr_assert_eq(dest, 0);
}

Test(is_label, error, .init = redirect_all_std)
{
    char **param = separate_params("salut les amis");
    index_t index;
    int dest;

    index.i = 0;
    index.label = initialize_label_list();
    index.bytes = 0;
    dest = is_label(param, index, 0, 0);
    cr_assert_eq(dest, -1);
}

Test(is_label, not_error, .init = redirect_all_std)
{
    char **param = separate_params("r1,%:live,%1");
    index_t index;
    int dest;

    index.i = 1;
    index.label = initialize_label_list();
    index.bytes = 0;
    dest = is_label(param, index, 1, 0);
    cr_assert_eq(dest, -2);
}

Test(is_index, error, .init = redirect_all_std)
{
    op_t op = op_tab[0];
    char **param = separate_params("r1,%:live,%1");
    instr_t *elem = initialize_instruction_list();
    index_t index;
    int dest;

    index.i = 1;
    index.label = initialize_label_list();
    index.bytes = 0;
    dest = is_index(op, param, &elem, index);
    cr_assert_eq(dest, 0);
}

Test(check_direct, error, .init = redirect_all_std)
{
    op_t op = op_tab[0];
    char **param = separate_params("r1,%:live,%1");
    instr_t *elem = initialize_instruction_list();
    index_t index;
    int dest;

    index.i = 1;
    index.label = initialize_label_list();
    index.bytes = 0;
    dest = check_direct(op, param, &elem, index);
    cr_assert_eq(dest, 84);
}

Test(check_parameter_instruction, error, .init = redirect_all_std)
{
    op_t op = op_tab[0];
    char *str = "r1,%:live,%1\nr1,%0,r1\n%1\n%:live\n";
    data_t *data = malloc(sizeof(data_t));
    int dest;

    data->name = "zork";
    data->comment = "I'M ALIIIIVE";
    data->size_prog = 23;
    data->data = initialize_instruction_list();
    data->label = initialize_label_list();
    dest = check_parameter_instruction(op, str, data, 1);
    cr_assert_eq(dest, -1);
}

Test(fill_params, error, .init = redirect_all_std)
{
    op_t op = op_tab[0];
    instr_t *elem = initialize_instruction_list();
    data_t *data = malloc(sizeof(data_t));

    data->name = "zork";
    data->comment = "I'M ALIIIIVE";
    data->size_prog = 23;
    data->data = initialize_instruction_list();
    data->label = initialize_label_list();
    fill_params(elem, data, op);
    cr_assert_eq(elem->code_instr, 1);
}

Test(input_processing, basic_test, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = { "./asm", "zork.s" };
    int dest = input_processing(ac, av);

    cr_assert_eq(dest, 84);
}

Test(check_register, error, .init = redirect_all_std)
{
    char **param = separate_params("r1,%:live,%1");
    instr_t *elem = initialize_instruction_list();
    index_t index;
    int dest;

    index.i = 1;
    index.label = initialize_label_list();
    index.bytes = 0;
    dest = check_register(param, &elem, index);
    cr_assert_eq(dest, 0);
}

Test(check_register, no_error, .init = redirect_all_std)
{
    char **param = separate_params("r1,%:live,%1");
    instr_t *elem = initialize_instruction_list();
    index_t index;
    int dest;

    index.i = 0;
    index.label = initialize_label_list();
    index.bytes = 0;
    dest = check_register(param, &elem, index);
    cr_assert_eq(dest, 1);
}

Test(check_name_comment, name, .init = redirect_all_std)
{
    bool dest = true;
    char *line = ".name";

    dest = check_name_comment(line);
    cr_assert_eq(dest, false);
}

Test(check_name_comment, comment, .init = redirect_all_std)
{
    bool dest = true;
    char *line = ".comment";

    dest = check_name_comment(line);
    cr_assert_eq(dest, false);
}

Test(check_name_comment, no_comment_name, .init = redirect_all_std)
{
    bool dest = true;
    char *line = ".commenzt";

    dest = check_name_comment(line);
    cr_assert_eq(dest, true);
}

Test(invalid_char, no_comment_name, .init = redirect_all_std)
{
    bool dest = true;
    char *line[] = { ".name", ".comment", "test", "tk13t"};

    dest = invalid_char(line);
    cr_assert_eq(dest, false);
}

Test(get_champion, ok_champ, .init = redirect_all_std)
{
    int dest = 0;
    char *str[] = { ".name \"zork\"\n", ".comment \"I'M ALIIIIVE\n", "\n",
                    "l2:\n", "sti r1,%:live,%1\n", "and r1,%0,r1\n",
                    "live: live %1\n", "zjmp %:live" };
    char *final_path = "zork.cor";

    dest = get_champion(str, final_path);
    cr_assert_eq(dest, 84);
}

Test(get_champion, no_name, .init = redirect_all_std)
{
    int dest = 0;
    char *str[] = { ".name \"zork\"\n", ".comment \"I'M ALIIIIVE\n", "\n",
                    "l2:\n", "sti r1,%:live,%1\n", "and r1,%0,r1\n",
                    "live: live %1\n", "zjmp %:live" };
    char *final_path = "zork.cor";

    dest = get_champion(str, final_path);
    cr_assert_eq(dest, 84);
}

Test(get_bytes_instruction, error, .init = redirect_all_std)
{
    char *str[] = { ".name \"zork\"\n", ".comment \"I'M ALIIIIVE\n", "\n",
                    "l2:\n", "sti r1,%:live,%1\n", "and r1,%0,r1\n",
                    "live: live %1\n", "zjmp %:live" };
    int dest = get_bytes_instruction(str, 1);

    cr_assert_eq(dest, 0);
}

Test(print_help, test, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/files/help", "r");

    print_help();
    cr_assert_stdout_eq(solved);
}
