/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** command_logout
*/

#include "rcodes.h"
#include <stdbool.h>

void *command_logout(void *args)
{
    bool isLogin = false; //check if the user is login
    char **cmd_args = NULL; //add the command arguments to be use in print_retcode
    (void)args;

    if (isLogin)
        print_retcode(203, cmd_args);
    else
        print_retcode(401, cmd_args);
    return NULL;
}
