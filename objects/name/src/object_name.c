/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_name
*/

/// \file objects/name/src/object_name.c

#include "object_name.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

name_t name_init(char *name_content)
{
    name_t new_name;

    if (strlen(name_content) > NAME_SIZE) {
        printf("%s Name init : %s.\n", NAME_INVALID_SIZE, name_content);
        return NAME_ERROR;
    }
    new_name = malloc(sizeof(name_t) * (NAME_SIZE + 1));
    if (new_name == NAME_ERROR)
        return NAME_ERROR;
    new_name[0] = '\0';
    strcat(new_name, name_content);
    return new_name;
}