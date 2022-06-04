/*
** EPITECH PROJECT, 2022
** Project
** File description:
** event_gestion
*/

/// \file server/src/core/event_gestion.c

#include "rcodes.h"
#include "object_wrapper.h"
#include "server.h"

void send_users_event_logout(server_data_t *serv, int code, char **args,
int sock)
{
    user_list_t *temp = NULL;

    for (size_t i = 0; i < serv->active_user_n; i++) {
        temp = serv->active_users[i];
        if (temp->disconnected != CONNECTED || !temp->is_auth ||
        sock == temp->user_peer->sock_fd)
            continue;
        print_retcode(code, cretcodes(args), temp->user_peer, true);
    }
}

void send_users_event_team(server_data_t *serv, int *info, char **args)
{
    user_list_t *temp = NULL;

    for (size_t i = 0; i < serv->active_user_n; i++) {
        temp = serv->active_users[i];
        if (temp->disconnected != CONNECTED || !temp->is_auth ||
        info[1] == temp->user_peer->sock_fd)
            continue;
        print_retcode(info[0], cretcodes(args), temp->user_peer, true);
    }
}

void send_users_event(server_data_t *serv, int code, char **args)
{
    user_list_t *temp = NULL;

    for (size_t i = 0; i < serv->active_user_n; i++) {
        temp = serv->active_users[i];
        if (temp->disconnected != CONNECTED || !temp->is_auth)
            continue;
        print_retcode(code, cretcodes(args), temp->user_peer, true);
    }
}

void send_users_event_create(server_data_t *serv, my_uuid_t *parent,
int *infos, char **args)
{
    my_uuid_t *team = NULL;
    user_list_t *temp = NULL;

    if (infos[0] == 604)
        team = get_associated_team_thread(serv->wrapper, parent);
    if (infos[0] == 606)
        team = parent;
    if (infos[0] == 607)
        team = get_associated_team_channel(serv->wrapper, parent);
    for (size_t i = 0; i < serv->active_user_n; i++) {
        temp = serv->active_users[i];
        if (temp->disconnected != CONNECTED || !temp->is_auth ||
        !user_is_sub_to_team(serv->wrapper, temp->user_uuid, team) ||
        infos[1] == temp->user_peer->sock_fd)
            continue;
        print_retcode(infos[0], cretcodes(args), temp->user_peer, true);
    }
}

void send_user_event(server_data_t *serv, my_uuid_t *user, int code,
char **args)
{
    user_list_t *temp = NULL;

    for (size_t i = 0; i < serv->active_user_n; i++) {
        temp = serv->active_users[i];
        if (temp->disconnected != CONNECTED || !temp->is_auth ||
        !my_uuid_cmp(user, temp->user_uuid))
            continue;
        print_retcode(code, cretcodes(args), temp->user_peer, true);
    }
}
