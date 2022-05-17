/*
** EPITECH PROJECT, 2022
** Project
** File description:
** team_dump
*/

/// \file objects/team/src/team_dump.c

#include "object_team.h"
#include <stdio.h>

void team_dump(team_t *team)
{
    printf("Team :\n");
    printf("\t");
    my_uuid_dump(team->uuid);
    printf("\t");
    name_dump(team->name);
    printf("\t");
    description_dump(team->description);
    printf("\tChannels :\n");
    for (int i = 0; i < team->channel_n; i++) {
        printf("\t\t");
        my_uuid_dump(team->channels[i]);
    }
    printf("\tUsers :\n");
    for (int i = 0; i < team->user_n; i++) {
        printf("\t\t");
        my_uuid_dump(team->users[i]);
    }
    fflush(NULL);
}