/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command_test
*/

#include <criterion/criterion.h>
#include "parser.h"
#include "cli_commands.h"

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

Test(compute_command, test12)
{
    char *cmd = "/login \"thomas";

    cr_assert_eq(compute_command(strdup(cmd)), -1);
}

Test(compute_command, test13)
{
    char *cmd = "/help ";

    cr_assert_eq(compute_command(strdup(cmd)), 0);
}

Test(compute_command, test14)
{
    char *cmd = "/send \"thomas\" \"salut\"";

    cr_assert_eq(compute_command(strdup(cmd)), 0);
}

Test(convert_command_to_structure, test15)
{
    char *cmd = strdup("/login \"thomas\"");
    cli_command_t *cli = convert_command_to_structure(cmd);

    cr_assert_str_eq(cli->name, "/login");
    cr_assert_str_eq(cli->arguments[0], "thomas");
}

Test(compute_command, test16)
{
    char *cmd = NULL;

    cr_assert_eq(compute_command(cmd), -1);
}

Test(get_cli_commands, test17)
{
    const cli_command_t *commands = get_cli_commands();

    cr_assert(commands != NULL);
}

Test(fill_command_arguments, test18)
{
    char **ret = fill_command_arguments(NULL, "/login");
    cr_assert(ret == NULL);
}