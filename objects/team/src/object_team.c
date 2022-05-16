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
    if ((new_team->channels = malloc(sizeof(my_uuid_t *))) == UUID_ERROR)
        return TEAM_ERROR;
    if ((new_team->users = malloc(sizeof(my_uuid_t *))) == UUID_ERROR)
        return TEAM_ERROR;
    new_team->n_user = 0;
    new_team->n_channel = 0;
    return new_team;
}

void team_destroy(team_t *team)
{
    if (team == TEAM_ERROR)
        return;
    my_uuid_destroy(team->uuid);
    name_destroy(team->name);
    description_destroy(team->description);
    free(team->channels);
    free(team->users);
    free(team);
}