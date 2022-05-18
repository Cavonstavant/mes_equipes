/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command_test
*/

#include <criterion/criterion.h>
#include "parser.h"

Test(compute_command, test01)
{
    cr_assert_eq(1, 1);
}

Test(compute_command, test02)
{
    char *cmd = "/login \"thomas\"";

    cr_assert_eq(compute_command(strdup(cmd)), 0);
}

Test(compute_command, test03)
{
    char *cmd = "/help";

    cr_assert_eq(compute_command(strdup(cmd)), 0);
}

Test(compute_command, test04)
{
    char *cmd = "/coucou";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test05)
{
    char *cmd = "/coucou salut";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test06)
{
    char *cmd = "/login salut";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test07)
{
    char *cmd = "/login ";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test08)
{
    char *cmd = "/login   \"coucou\"";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test09)
{
    char *cmd = "login \"thomas\"";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test10)
{
    char *cmd = "/login \"thomas\" \"thomas\"";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test11)
{
    char *cmd = "/login\"thomas\"";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}