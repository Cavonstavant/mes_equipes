/*
** EPITECH PROJECT, 2022
** Project
** File description:
** uuid_dump
*/

/// \file objects/uuid/src/uuid_dump.c

#include "object_uuid.h"
#include <stdio.h>

void my_uuid_dump(my_uuid_t *uuid)
{
    printf("Uuid : %s\n", uuid->uuid.repr);
}