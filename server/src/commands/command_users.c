/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** command_users
*/

#include "rcodes.h"

/// \brief Print users informations
/// \param void *Data of all clients
static void print_users_data(void *data)
{
    // fill the function to print the data of all clients
}

void *command_users(void *args)
{
    (void)args;
    void *data = NULL; //define the data about users
    char **cmd_args = NULL; // command's arguments

    if (data) {
        print_users_data(data);
        print_retcode(200, cmd_args);
    } else {
        print_retcode(310, cmd_args);
    }
    return NULL;
}