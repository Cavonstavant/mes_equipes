/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_remove
*/

/// \file objects/user/src/user_remove.c

#include "object_user.h"
#include <stdlib.h>

bool user_remove_team(user_t *user, my_uuid_t *team)
{
    int index = my_uuid_find(user->teams, user->team_n, team);
    my_uuid_t **new = malloc(sizeof(my_uuid_t *) * (user->team_n + 2));
    int count = 0;

    if (index == -1 || new == NULL)
        return OPERATION_FAILED;
    for (int i = 0; i < user->team_n; i++) {
        if (i == index)
            continue;
        new[count] = user->teams[i];
        count++;
    }
    free(user->teams);
    user->teams = new;
    user->team_n -= 1;
    return OPERATION_SUCCESS;
}
