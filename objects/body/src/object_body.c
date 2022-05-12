/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_body
*/

/// \file objects/body/src/object_body.c

#include "object_body.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

body_t body_init(char *body_content)
{
    body_t new_body;

    if (strlen(body_content) > BODY_SIZE) {
        printf("%s Body init : %s.\n", BODY_INVALID_SIZE, body_content);
        return BODY_ERROR;
    }
    new_body = malloc(sizeof(body_t) * (BODY_SIZE + 1));
    if (new_body == BODY_ERROR)
        return BODY_ERROR;
    new_body[0] = '\0';
    strcat(new_body, body_content);
    return new_body;
}

void body_destroy(body_t body_to_destroy)
{
    if (body_to_destroy != BODY_ERROR)
        free(body_to_destroy);
}