/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_setter
*/

/// \file objects/user/src/user_setter.c

#include "object_user.h"
#include <stdlib.h>

void user_edit_uuid(user_t *user, char *uuid)
{
    my_uuid_edit_content(user->uuid, uuid);
}

void user_edit_name(user_t *user, char *name)
{
    name_edit_content(user->name, name);
}

void user_edit_status(user_t *user, status_t status)
{
    status_edit_content(&user->status, status);
}

bool user_add_team(user_t *user, my_uuid_t *team)
{
    user->teams = realloc(user->teams,
    sizeof(my_uuid_t *) * (user->team_n + 2));
    if (user->teams == NULL)
        return OPERATION_FAILED;
    user->teams[user->team_n] = team;
    user->team_n += 1;
    return OPERATION_SUCCESS;
}

bool user_add_conversation(user_t *user, my_uuid_t *conversation)
{
    user->conversations = realloc(user->conversations,
    sizeof(my_uuid_t *) * (user->conversation_n + 2));
    if (user->conversations == NULL)
        return OPERATION_FAILED;
    user->conversations[user->conversation_n] = conversation;
    user->conversation_n += 1;
    return OPERATION_SUCCESS;
}
