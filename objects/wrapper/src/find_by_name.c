/*
** EPITECH PROJECT, 2022
** Project
** File description:
** find_by_name
*/

/// \file objects/wrapper/src/find_by_name.c

#include "object_wrapper.h"

my_uuid_t *find_channel_by_name(object_wrapper_t *wrapper, char *name)
{
    for (int i = 0; i < wrapper->channel_n; i++)
        if (strcmp(wrapper->channels[i]->name, name) == 0)
            return wrapper->channels[i]->uuid;
    return OBJECT_NOT_FOUND;
}

my_uuid_t *find_team_by_name(object_wrapper_t *wrapper, char *name)
{
    for (int i = 0; i < wrapper->team_n; i++)
        if (strcmp(wrapper->teams[i]->name, name) == 0)
            return wrapper->teams[i]->uuid;
    return OBJECT_NOT_FOUND;
}