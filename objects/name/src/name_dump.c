/*
** EPITECH PROJECT, 2022
** Project
** File description:
** name_dump
*/

/// \file objects/name/src/name_dump.c

#include "object_name.h"
#include <stdio.h>

void name_dump(name_t name)
{
    printf("Name : %s\n", name);
    fflush(NULL);
}
