/*
** EPITECH PROJECT, 2022
** Project
** File description:
** auth_command
*/

/// \file server/src/auth_command.c

#include "cli_commands.h"
#include "rcodes.h"

bool command_logout(cli_command_t *command,
user_list_t *user_info, server_data_t *server_data)
{
    (void) command;
    (void) user_info;
    (void) server_data;
    print_retcode(203, NULL, user_info->user_peer);
    user_info->disconnected = TO_LOGOUT;
    return true;
}