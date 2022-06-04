/*
** EPITECH PROJECT, 2022
** Project
** File description:
** description_dump
*/

/// \file objects/description/src/description_dump.c

#include "object_description.h"
#include <stdio.h>

void description_dump(description_t desc)
{
    printf("Description : %s\n", desc);
    fflush(NULL);
}
