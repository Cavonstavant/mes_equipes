/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** command_send
*/

/// \file server/src/commands/command_send.c

#include "rcodes.h"

void *command_send(void *args)
{
    bool user_login = false; //todo Check if the user is login
    char **cmd_args = NULL;
    char *uuid = NULL;

    if (!user_login)
        print_retcode(401, cmd_args);
    else if (!find_uuid(uuid))
        print_retcode(311, uuid);
    else
        print_retcode(200, cmd_args);
    return NULL;
}
