/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** cli_commands
*/

/// \file server/src/core/cli_commands.c

#include "cli_commands.h"
#include <stddef.h>
#include <string.h>

/// \brief List all available command
static const cli_command_t commands[14] = {
    {"/help", NULL, &command_help},
    {"/login", (char *[]){"", NULL}, &command_login},
    {"/logout", NULL, &command_logout},
    {"/users", NULL, &command_users},
    {"/user", (char *[]){"", NULL}, &command_user},
    {"/send", (char *[]){"", "", NULL}, &command_send},
    {"/messages", (char *[]){"", NULL}, &command_messages},
    {"/subscribed", (char *[]){"", NULL}, &command_subscribed},
    {"/subscribe", (char *[]){"", NULL}, &command_subscribe},
    {"/unsubscribe", (char *[]){"", NULL}, &command_unsubscribe},
    {"/use", (char *[]){"", "", "", NULL}, &command_use},
    {"/create", (char *[]){"", "", NULL}, &command_create},
    {"/list", NULL, &command_list},
    {"/info", NULL, &command_info}
};

const cli_command_t *get_cli_command_by_name(char *command)
{
    for (int i = 0; i < COMMAND_NUMBER; i++) {
        if (strncmp(command, commands[i].name, strlen(commands[i].name)) == 0)
            return (&commands[i]);
    }
    return (NULL);
}

const cli_command_t *get_cli_commands(void)
{
    return (commands);
}
