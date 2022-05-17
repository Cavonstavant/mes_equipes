/*
** EPITECH PROJECT, 2022
** Project
** File description:
** team_setter
*/

/// \file objects/team/src/team_setter.c

#include "object_team.h"
#include <stdlib.h>

void team_edit_uuid(team_t *team, char *uuid)
{
    my_uuid_edit_content(team->uuid, uuid);
}

void team_edit_name(team_t *team, char *name)
{
    name_edit_content(team->name, name);
}

void team_edit_description(team_t *team, char *description)
{
    description_edit_content(team->description, description);
}

bool team_add_channel(team_t *team, my_uuid_t *channel)
{
    team->channels = realloc(team->channels,
    sizeof(my_uuid_t *) * (team->channel_n + 2));
    if (team->channels == NULL)
        return OPERATION_FAILED;
    team->channels[team->channel_n] = channel;
    team->channel_n += 1;
    return OPERATION_SUCCESS;
}

bool team_add_user(team_t *team, my_uuid_t *user)
{
    team->users = realloc(team->users,
    sizeof(my_uuid_t *) * (team->user_n + 2));
    if (team->users == NULL)
        return OPERATION_FAILED;
    team->users[team->user_n] = user;
    team->channel_n += 1;
    return OPERATION_SUCCESS;
}