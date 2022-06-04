/*
** EPITECH PROJECT, 2022
** Project
** File description:
** uuid_setter
*/

/// \file objects/uuid/src/uuid_setter.c

#include "object_uuid.h"

int my_uuid_edit_content(my_uuid_t *uuid, char *content)
{
    return w_uuid_parse_from_string(&uuid->uuid, content);
}

int my_uuid_find(my_uuid_t **list, int list_n, my_uuid_t *to_find)
{
    for (int i = 0; i < list_n; i++)
        if (!strcmp(list[i]->uuid.repr, to_find->uuid.repr))
            return i;
    return -1;
}

my_uuid_t *my_uuid_from_string(char *repr)
{
    my_uuid_t *uuid = my_uuid_init(TEM_);

    if (my_uuid_edit_content(uuid, repr) == -1)
        return NULL;
    return uuid;
}
