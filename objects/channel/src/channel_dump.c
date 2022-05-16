/*
** EPITECH PROJECT, 2022
** Project
** File description:
** channel_dump
*/

/// \file objects/channel/src/channel_dump.c

#include "object_channel.h"
#include <stdio.h>

void channel_dump(channel_t *channel)
{
    printf("Comment :\n");
    printf("\t");
    my_uuid_dump(channel->uuid);
    printf("\t");
    name_dump(channel->name);
    description_dump(channel->description);
    printf("\tParent : ");
    my_uuid_dump(channel->team);
    printf("\tChild :\n");
    for (int i = 0; i < channel->n_threads; i++) {
        printf("\t\t");
        my_uuid_dump(channel->threads[i]);
    }
    fflush(NULL);
}