/*
** EPITECH PROJECT, 2022
** Project
** File description:
** body_setter
*/

/// \file objects/body/src/body_setter.c

#include "object_body.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void body_edit_content(body_t body, char *body_content)
{
    if (strlen(body_content) > BODY_SIZE)
        return;
    body[0] = '\0';
    strcat(body, body_content);
}