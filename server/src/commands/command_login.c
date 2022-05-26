/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** login_command
*/

#include "rcodes.h"

void *command_login(void *arg)
{
    bool existing_user = false; // call command to know if client exist
    char **cmd_args = NULL; //arguments of the command

    if (existing_user) {
        print_retcode(201, cmd_args);
    } else {
        print_retcode(202, cmd_args);
    }
    return NULL;
}
