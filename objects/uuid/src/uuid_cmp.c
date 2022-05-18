/*
** EPITECH PROJECT, 2022
** Project
** File description:
** uuid_cmp
*/

/// \file objects/uuid/src/uuid_cmp.c

#include "object_uuid.h"

bool my_uuid_cmp(my_uuid_t *first, my_uuid_t *second)
{
    if (!strcmp(first->uuid.repr, second->uuid.repr))
        return MATCHED;
    return MISMATCHED;
}