/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** check_command
*/

#include "parser.h"
#include <stddef.h>

static const cli_command_t *commands[14] = {
    {"/help", NULL, &help_command},
    {"/login", {""}, &login_command},
    {"/logout", NULL, &logout_command},
    {"/users", NULL, &users_command},
    {"/user", {""}, &user_command},
    {"/send", {"", ""}, &send_command},
    {"/messages", {""}, &messages_command},
    {"/subscribe", {""}, &subscribe_command},
    {"/subscribed", {""}, &subscribed_command},
    {"/unsubscribe", {""}, &unsubscribe_command},
    {"/use", {""}, &use_command},
    {"/create", {"", ""}, &create_command},
    {"/list", NULL, &list_command},
    {"/info", NULL, &info_command}
};

int check_parser(char **arguments)
{

    return (0);
}
