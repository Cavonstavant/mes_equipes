/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** login_command
*/

#include "rcode.h"

static int check_login_arg_number(void *arg)
{
    return (0);
}

void *login_command(void *arg)
{
    bool existing_user = false; // call command to know if client exist

    if (check_login_arg_number(arg) < 0) {
        printf("%s\n", rcode_510);
        return ((void *)0);
    }
    if (existing_user) {
        printf("%s\n", rcode_201);
    } else {
        printf("%s\n", rcode_202);
    }
    return ((void *)0);
}