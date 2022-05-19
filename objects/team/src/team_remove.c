/*
** EPITECH PROJECT, 2022
** Project
** File description:
** team_remove
*/

/// \file objects/team/src/team_remove.c

#include "object_team.h"
#include <stdlib.h>

bool team_remove_user(team_t *team, my_uuid_t *user)
{
    int index = my_uuid_find(team->users, team->user_n, user);
    my_uuid_t **new = malloc(sizeof(my_uuid_t *) * (team->user_n + 2));
    int count = 0;

    if (index == -1 || new == NULL)
        return OPERATION_FAILED;
    for (int i = 0; i < team->user_n; i++) {
        if (i == index)
            continue;
        new[count] = team->users[i];
        count++;
    }
    free(team->users);
    team->users = new;
    team->user_n -= 1;
    return OPERATION_SUCCESS;
}