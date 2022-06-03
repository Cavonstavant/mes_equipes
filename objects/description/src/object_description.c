/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_description
*/

/// \file objects/description/src/object_description.c

#include "object_description.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

description_t description_init(char *description_content)
{
    description_t new_description;

    if (strlen(description_content) > DESCRIPTION_SIZE) {
        printf("%s Description init : %s.\n",
        DESCRIPTION_INVALID_SIZE, description_content);
        return DESCRIPTION_ERROR;
    }
    new_description = malloc(sizeof(description_t) * (DESCRIPTION_SIZE + 1));
    if (new_description == DESCRIPTION_ERROR)
        return DESCRIPTION_ERROR;
    new_description[0] = '\0';
    strcat(new_description, description_content);
    return new_description;
}

void description_destroy(description_t description_to_destroy)
{
    if (description_to_destroy != DESCRIPTION_ERROR)
        free(description_to_destroy);
}
