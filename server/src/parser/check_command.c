/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** check_command
*/

#include "parser.h"
#include <stddef.h>

static const cli_command_t *commands[14] = {
    {"/help", NULL, &help_command},
    {"/login", {"", NULL}, &login_command},
    {"/logout", NULL, &logout_command},
    {"/users", NULL, &users_command},
    {"/user", {"", NULL}, &user_command},
    {"/send", {"", "", NULL}, &send_command},
    {"/messages", {"", NULL}, &messages_command},
    {"/subscribe", {"", NULL}, &subscribe_command},
    {"/subscribed", {"", NULL}, &subscribed_command},
    {"/unsubscribe", {"", NULL}, &unsubscribe_command},
    {"/use", {"", NULL}, &use_command},
    {"/create", {"", "", NULL}, &create_command},
    {"/list", NULL, &list_command},
    {"/info", NULL, &info_command}
};

static int count_tab_len(char **tab)
{
    int arg_count = 0;

    while (tab[arg_count]) {
        arg_count++;
    }
    return (arg_count);
}

static int command_find(char **arguments, cli_command_t *commands)
{
    int arg_count = count_tab_len(arguments);

    if (strcmp(arguments[0], commands->name) == 0) {
        if (arg_count == count_tab_len(commands->arguments) + 1) {
            return (1);
        }
    }
    return (0);
}

int check_parser(char **arguments)
{
    for (int i = 0; i < 14; i++) {
        if (command_find(arguments, &commands[i])) {
            return (1);
        }
    }
    return (0);
}
