/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_status
*/

/// \file objects/status/src/object_status.c

#include "object_status.h"

status_t status_init(void)
{
    status_t new_status;

    new_status = OFFLINE;
    return new_status;
}

void status_destroy(status_t status_to_destroy)
{
    (void) status_to_destroy;
}