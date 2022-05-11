/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** cli_commands
*/

/// \file server/src/parser/cli_commands.c

#include "cli_commands.h"
#include <stddef.h>

/// \brief List all available command
static const cli_command_t commands[14] = {
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

const cli_command_t *get_cli_commands()
{
    return (commands);
}
