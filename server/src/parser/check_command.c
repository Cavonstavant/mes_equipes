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

int check_parser(char **arguments)
{
    int arg_count = count_tab_len(arguments);

    return (0);
}
