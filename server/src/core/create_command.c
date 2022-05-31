/*
** EPITECH PROJECT, 2022
** Project
** File description:
** create_command
*/

/// \file server/src/create_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"
#include "upper_component_adding.h"

/// TO REFACTO

bool command_create(cli_command_t *command,
user_list_t *user, server_data_t *serv_data)
{
    if (!user->is_auth) {
        print_retcode(401, NULL, user->user_peer);
        return true;
    }
    if (find_team_by_name(serv_data->wrapper, command->arguments[0])) {
        print_retcode(320, NULL, user->user_peer);
        return true;
    }
    if (wrapper_adding_team(serv_data->wrapper, (team_creation_t) {
        command->arguments[0],
        command->arguments[1]
    }) == false) {
        print_retcode(503, NULL, user->user_peer);
        return true;
    }
    print_retcode(200, NULL, user->user_peer);
    server_event_team_created(find_team_by_name(serv_data->wrapper,
    command->arguments[0])->uuid.repr, command->arguments[0],
    user->user_uuid->uuid.repr);
    return true;
}
