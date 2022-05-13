/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_team
*/

/// \file objects/team/src/object_team.c

#include "object_team.h"
#include <stdlib.h>

team_t *team_init(team_creation_t content)
{
    team_t *new_team = malloc(sizeof(team_t) * 1);

    if (new_team == TEAM_ERROR)
        return TEAM_ERROR;
    if ((new_team->name = name_init(content.name)) == NAME_ERROR)
        return TEAM_ERROR;
    if ((new_team->description = description_init(content.description))
        == DESCRIPTION_ERROR)
        return TEAM_ERROR;
    if ((new_team->uuid = my_uuid_init(TEM_)) == UUID_ERROR)
        return TEAM_ERROR;
    if ((new_team->channels = malloc(sizeof(my_uuid_t *) * 20)) == UUID_ERROR)
        return TEAM_ERROR;
    if ((new_team->users = malloc(sizeof(my_uuid_t *) * 40)) == UUID_ERROR)
        return TEAM_ERROR;
    new_team->users[0] = NULL;
    new_team->channels[0] = NULL;
    return new_team;
}