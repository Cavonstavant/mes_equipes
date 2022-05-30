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

child_list_t get_subscribed_user_of_team(object_wrapper_t *wrapper,
my_uuid_t *team_uuid)
{
    team_t *team = wrapper_find_team(wrapper, team_uuid);

    if (team == OBJECT_NOT_FOUND)
        return (child_list_t) {
            OBJECT_NOT_FOUND,
            -1
        };
    return (child_list_t) {
        team->users,
        team->user_n
    };
}