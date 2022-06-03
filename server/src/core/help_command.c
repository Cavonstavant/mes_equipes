/*
** EPITECH PROJECT, 2022
** Project
** File description:
** help_command
*/

/// \file server/src/help_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

bool command_help(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    (void) cmd;
    (void) data;
    return print_retcode(221, cretcodes((char *[]) {"READ THE PDF...",
    "Btw, you loose", NULL}), user->user_peer, true);
}
