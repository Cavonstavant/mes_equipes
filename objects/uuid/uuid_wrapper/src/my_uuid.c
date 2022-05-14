/*
** EPITECH PROJECT, 2022
** uuid_wrapper
** File description:
** uuid_wrapper
*/

#include "my_uuid.h"
#include <string.h>

int my_uuid_generate(w_uuid_t *out, my_uuid_prefix_t prefix)
{
    if (prefix < 0 || prefix > 7)
        return (-1);
    bzero(out, sizeof(w_uuid_t));
    uuid_generate(out->uuid);
    strcpy(out->repr, get_prefix(prefix));
    uuid_unparse(out->uuid, out->repr + 4);
    return (0);
}

my_uuid_prefix_t my_uuid_get_prefix(w_uuid_t *uuid)
{
    if (uuid == NULL)
        return (-1);
    for (int i = 0; i < MY_UUID_PREFIX_COUNT; i++) {
        if (strncmp(uuid->repr, get_prefix(i), 4) == 0)
            return (i);
    }
    return (-1);
}