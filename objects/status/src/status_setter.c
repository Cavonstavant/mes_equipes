/*
** EPITECH PROJECT, 2022
** Project
** File description:
** status_setter
*/

/// \file objects/status/src/status_setter.c

#include "object_status.h"

void status_edit_content(status_t *status, bool content)
{
    *status = content;
}