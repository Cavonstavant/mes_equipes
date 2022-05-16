/*
** EPITECH PROJECT, 2022
** Project
** File description:
** body_dump
*/

/// \file objects/body/src/body_dump.c

#include "object_body.h"
#include <stdio.h>

void body_dump(body_t body_to_destroy)
{
    printf("Body object :\n");
    printf("\tContent :\n");
    printf("\t\t%s\n", body_to_destroy);
    fflush(NULL);
}