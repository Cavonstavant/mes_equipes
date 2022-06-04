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
