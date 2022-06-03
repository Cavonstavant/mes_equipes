/*
** EPITECH PROJECT, 2022
** Project
** File description:
** status_dump
*/

/// \file objects/status/src/status_dump.c

#include "object_status.h"
#include <stdio.h>

void status_dump(status_t status)
{
    printf("Status : %s\n", ((status == ONLINE) ? "online" : "offline"));
    fflush(NULL);
}
