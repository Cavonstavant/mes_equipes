/*
** EPITECH PROJECT, 2022
** Project
** File description:
** get_associated_team
*/

/// \file objects/wrapper/src/get_associated_team.c

#include "object_wrapper.h"

my_uuid_t *get_associated_team_channel(object_wrapper_t *wrapper,
my_uuid_t *channel_uuid)
{
    channel_t *channel = wrapper_find_channel(wrapper, channel_uuid);

    if (channel == OBJECT_NOT_FOUND)
        return OBJECT_NOT_FOUND;
    return channel->team;
}