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
    bool user_login = false; //todo Complete the variables
    char *uuid = NULL;
    char **cmd_arg = NULL;

    if (!user_login)
        print_retcode(401, cmd_args);
    else if (!find_uuid(uuid))
        print_retcode(311, cmd_args);
    else
        print_retcode(200, cmd_args);
    return NULL;
}
