/*
** EPITECH PROJECT, 2022
** Project
** File description:
** lower_component_get
*/

/// \file objects/wrapper/src/lower_component_get.c

#include "object_wrapper.h"

message_t *wrapper_find_message(object_wrapper_t *wrapper, my_uuid_t *find)
{
    for (int i = 0; i < wrapper->message_n; i++) {
        if (my_uuid_cmp(wrapper->messages[i]->uuid, find))
            return wrapper->messages[i];
    }
    return OBJECT_NOT_FIND;
}
