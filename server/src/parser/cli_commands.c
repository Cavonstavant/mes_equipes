/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** cli_commands
*/

/// \file server/src/parser/cli_commands.c

#include "cli_commands.h"
#include <stddef.h>
#include <string.h>

/// \brief List all available command
static const cli_command_t commands[14] = {
    {"/help", NULL, /*&help_command*/NULL},
    {"/login", (char *[]){"", NULL}, /*&login_command*/NULL},
    {"/logout", NULL, /*&logout_command*/NULL},
    {"/users", NULL, /*&users_command*/NULL},
    {"/user", (char *[]){"", NULL}, /*&user_command*/NULL},
    {"/send", (char *[]){"", "", NULL}, /*&send_command*/NULL},
    {"/messages", (char *[]){"", NULL}, /*&messages_command*/NULL},
    {"/subscribe", (char *[]){"", NULL}, /*&subscribe_command*/NULL},
    {"/subscribed", (char *[]){"", NULL}, /*&subscribed_command*/NULL},
    {"/unsubscribe", (char *[]){"", NULL}, /*&unsubscribe_command*/NULL},
    {"/use", (char *[]){"", NULL}, /*&use_command*/NULL},
    {"/create", (char *[]){"", "", NULL}, /*&create_command*/NULL},
    {"/list", NULL, /*&list_command*/NULL},
    {"/info", NULL, /*&info_command*/NULL}
};

const cli_command_t *get_cli_command_by_name(char *command)
{
    for (int i = 0; i < COMMAND_NUMBER; i++) {
        if (strcmp(command, commands[i].name) == 0)
            return (&commands[i]);
    }
    return (NULL);
}

const cli_command_t *get_cli_commands(void)
{
    return (commands);
}
