/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_and_team_relation
*/

/// \file objects/wrapper/src/user_and_team_relation.c

#include "object_wrapper.h"

child_list_t get_subscribed_team_of_user(object_wrapper_t *wrapper,
my_uuid_t *user_uuid)
{
    user_t *user = wrapper_find_user(wrapper, user_uuid);

    if (user == OBJECT_NOT_FOUND)
        return (child_list_t) {
            OBJECT_NOT_FOUND,
            -1
        };
    return (child_list_t) {
        user->teams,
        user->team_n
    };
}