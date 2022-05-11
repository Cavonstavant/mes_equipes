/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_uuid
*/

/// \file objects/uuid/src/object_uuid.c

#include "object_uuid.h"

my_uuid_t my_uuid_init(uuid_type_t uuid_content)
{
    my_uuid_t new_uuid;

    new_uuid.uuid = UUID_ERROR; /// CALL UUID LIBRARY
    new_uuid.type = uuid_content;
    return new_uuid;
}