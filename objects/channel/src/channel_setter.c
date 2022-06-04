/*
** EPITECH PROJECT, 2022
** Project
** File description:
** channel_setter
*/

/// \file objects/channel/src/channel_dump.c

#include "object_channel.h"
#include <stdlib.h>

void channel_edit_uuid(channel_t *channel, char *uuid)
{
    my_uuid_edit_content(channel->uuid, uuid);
}

void channel_edit_name(channel_t *channel, char *name)
{
    name_edit_content(channel->name, name);
}

void channel_edit_parent(channel_t *channel, char *parent)
{
    my_uuid_edit_content(channel->team, parent);
}

bool channel_add_threads(channel_t *channel, my_uuid_t *thread)
{
    channel->threads = realloc(channel->threads,
    sizeof(my_uuid_t *) * (channel->threads_n + 2));
    if (channel->threads == NULL)
        return OPERATION_FAILED;
    channel->threads[channel->threads_n] = thread;
    channel->threads_n += 1;
    return OPERATION_SUCCESS;
}
