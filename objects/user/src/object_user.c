/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_user
*/

/// \file objects/user/src/object_user.c

#include "object_user.h"
#include <stdlib.h>

user_t *user_init(user_creation_t content)
{
    user_t *new_user = malloc(sizeof(user_t) * 1);

    if (new_user == USER_ERROR)
        return USER_ERROR;
    if ((new_user->uuid = my_uuid_init(USR_)) == UUID_ERROR)
        return USER_ERROR;
    if ((new_user->name = name_init(content.name)) == NAME_ERROR)
        return USER_ERROR;
    if ((new_user->teams = malloc(sizeof(my_uuid_t *))) == UUID_ERROR)
        return USER_ERROR;
    if ((new_user->conversations = malloc(sizeof(my_uuid_t *)))
        == UUID_ERROR)
        return USER_ERROR;
    new_user->team_n = 0;
    new_user->conversation_n = 0;
    new_user->status = status_init();
    status_edit_content(&new_user->status, content.status);
    return new_user;
}

void user_destroy(user_t *user)
{
    if (user == USER_ERROR)
        return;
    my_uuid_destroy(user->uuid);
    name_destroy(user->name);
    status_destroy(user->status);
    free(user->teams);
    free(user->conversations);
    free(user);
}
