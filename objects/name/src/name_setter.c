/*
** EPITECH PROJECT, 2022
** Project
** File description:
** name_setter
*/

/// \file objects/name/src/name_setter.c

#include "object_name.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void name_edit_content(name_t name, char *content)
{
    if (strlen(content) > NAME_SIZE)
        return;
    name[0] = '\0';
    strcat(name, content);
}
