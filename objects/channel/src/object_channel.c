/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_channel
*/

/// \file objects/channel/src/object_channel.c

#include "object_channel.h"
#include <stdlib.h>

channel_t *channel_init(channel_creation_t content)
{
    channel_t *new_channel = malloc(sizeof(channel_t) * 1);

    if (new_channel == CHANNEL_ERROR)
        return CHANNEL_ERROR;
    new_channel->team = content.team;
    if ((new_channel->name = name_init(content.name)) == NAME_ERROR)
        return CHANNEL_ERROR;
    if ((new_channel->description = description_init(content.description))
        == DESCRIPTION_ERROR)
        return CHANNEL_ERROR;
    if ((new_channel->uuid = my_uuid_init(CHA_)) == UUID_ERROR)
        return CHANNEL_ERROR;
    if ((new_channel->threads = malloc(sizeof(my_uuid_t *))) == UUID_ERROR)
        return CHANNEL_ERROR;
    new_channel->threads_n = 0;
    return new_channel;
}

void channel_destroy(channel_t *channel)
{
    if (channel == CHANNEL_ERROR)
        return;
    name_destroy(channel->name);
    description_destroy(channel->description);
    my_uuid_destroy(channel->uuid);
    free(channel->threads);
    free(channel);
}