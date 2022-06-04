/*
** EPITECH PROJECT, 2022
** Project
** File description:
** description_setter
*/

/// \file objects/description/src/description_setter.c

#include "object_description.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void description_edit_content(description_t desc, char *content)
{
    if (strlen(content) > DESCRIPTION_SIZE)
        return;
    desc[0] = '\0';
    strcat(desc, content);
}
