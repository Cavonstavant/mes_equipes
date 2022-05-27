/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** command_user
*/

#include "rcodes.h"
#include <stdbool.h>

static bool find_uuid(char *uuid)
{
    (void)uuid;
    if (1) //todo write the correct condition
        return true;
    return false;
}

void *command_user(void *args)
{
    char *uuid = NULL;
    char **cmd_arg = NULL;

    if (!find_uuid(uuid))
        print_retcode(311, cmd_args);
    else
        print_retcode(200, cmd_args);
    return NULL;
}
