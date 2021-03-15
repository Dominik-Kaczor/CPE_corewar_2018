/*
** EPITECH PROJECT, 2019
** Tests generic
** File description:
** This set of tests test the program function by function
*/

#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

int main_test(int ac, char **av, char **env);
extern char **environ;

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(args_check, no_env, .init = redirect_all_std)
{
    int ac = 1;
    char *av[] = { "test" };
    char **env = NULL;
    int dest = args_check(ac, av, env);

    cr_assert_eq(dest, 84);
}

Test(args_check, bad_file_type, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = { "test", "zork.s" };
    char *env[] = { "test" };
    int dest = args_check(ac, av, env);

    cr_assert_eq(dest, 84);
}

Test(args_check, all_ok, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = { "test", "zork.cor" };
    char *env[] = { "test" };
    int dest = args_check(ac, av, env);

    cr_assert_eq(dest, 0);
}

Test(main_test, good, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = { "test", "tests/zork.cor" };
    int dest = main_test(ac, av, environ);

    cr_assert_eq(dest, 0);
}

Test(main_test, several_champs_good, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = { "test", "tests/zork.cor", "tests/42.cor", "tests/bill.cor",
                   "tests/abel.cor", "tests/ebola.cor", "tests/pdd.cor",
                   "tests/tyron.cor" };
    int dest = main_test(ac, av, environ);

    cr_assert_eq(dest, 0);
}

Test(htoi, big_hex)
{
    char *test = "3fa";
    int dest = 0;

    dest = htoi(test);
    cr_assert_eq(dest, 1018);
}
