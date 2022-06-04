/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_uuid
*/

/// \file objects/uuid/src/object_uuid.c

#include "object_uuid.h"
#include <stdlib.h>

my_uuid_t *my_uuid_init(uuid_type_t uuid_content)
{
    my_uuid_t *new_uuid = malloc(sizeof(my_uuid_t) * 1);

    if (new_uuid == UUID_ERROR)
        return UUID_ERROR;
    if (my_uuid_generate(&(new_uuid->uuid),
    (my_uuid_prefix_t) uuid_content) == -1) {
        free(new_uuid);
        return UUID_ERROR;
    }
    return new_uuid;
}

void my_uuid_destroy(my_uuid_t *uuid_to_destroy)
{
    if (uuid_to_destroy != UUID_ERROR)
        free(uuid_to_destroy);
}
