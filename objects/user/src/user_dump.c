/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_dump
*/

/// \file objects/user/src/user_dump.c

#include "object_user.h"
#include <stdio.h>

void user_dump(user_t *user)
{
    printf("User :\n");
    printf("\t");
    my_uuid_dump(user->uuid);
    printf("\t");
    name_dump(user->name);
    printf("\t");
    status_dump(user->status);
    printf("\tTeams :\n");
    for (int i = 0; i < user->n_team; i++) {
        printf("\t\t");
        my_uuid_dump(user->teams[i]);
    }
    printf("\tConversations :\n");
    for (int i = 0; i < user->n_conversation; i++) {
        printf("\t\t");
        my_uuid_dump(user->conversations[i]);
    }
    fflush(NULL);
}