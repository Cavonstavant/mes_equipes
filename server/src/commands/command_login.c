/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** login_command
*/

#include "rcode.h"

void *command_login(void *arg)
{
    bool existing_user = false; // call command to know if client exist
    char *username = ""; // need to define username

    if (existing_user) {
        printf(rcode_201, username);
    } else {
        printf(rcode_202, username);
    }
    return ((void *)0);
}
