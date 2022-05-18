/*
** EPITECH PROJECT, 2022
** Project
** File description:
** upper_component_get
*/

/// \file objects/wrapper/src/upper_component_get.c

#include "object_wrapper.h"

channel_t *wrapper_find_channel(object_wrapper_t *wrapper, my_uuid_t *find)
{
    for (int i = 0; i < wrapper->channel_n; i++) {
        if (my_uuid_cmp(wrapper->channels[i]->uuid, find))
            return wrapper->channels[i];
    }
    return OBJECT_NOT_FIND;
}