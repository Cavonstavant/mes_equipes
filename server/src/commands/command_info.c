/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** command_info
*/

#include <stdio.h>

void *help_command(void *arg)
{
    printf("==========HELP==========\n");
    printf("/help: show help.\n");
    printf("/login [\"user_name\"]: set the user_name used by client.\n");
    printf("/logout: disconnect the client from the server.\n");
    printf("/users: get the list of all users that exist on the domain.\n");
    printf("/user [\"user_uuid\"]: get information about a user.\n");
    printf("/send [\"user_uuid\"] [\"message_body\"]: send a message to a user.\n");
    printf("/messages [\"user_uuid\"]: list all messages exchange with an user.\n");
    printf("/subscribe [\"team_uuid\"]: subscribe to the event of a team and its sub directories (enable reception of all events from a team).\n");
    printf("/subscribed ?[\"team_uuid\"]: list all subscribed teams or list all users subscribed to a team.\n");
    printf("/unsubscribe [\"team_uuid\"]: unsubscribe from a team.\n");
    printf("/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"]: use specify a context team/channel/thread/\n");
    printf("/create: based on what is being used create the sub resource.\n");
    printf("/list: based on what is being used list all the sub resources.\n");
    printf("/info: based on what is being used list the current.\n");
    return ((void *)0);
}