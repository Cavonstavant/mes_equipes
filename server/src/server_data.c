/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_data
*/

/// \file server/src/server_data.c

#include "server.h"
#include <stdlib.h>

server_data_t *init_server_data(long port)
{
    server_data_t *server_data = malloc(sizeof(server_data_t) * 1);

    (void) port;
    if (server_data == NULL)
        return NULL;
    server_data->wrapper = wrapper_init();
    if (server_data->wrapper == NULL)
        return NULL;
    server_data->active_users = malloc(sizeof(user_list_t *) * 1);
    if (server_data->active_users == NULL)
        return NULL;
    server_data->active_users[0] = NULL;
    server_data->active_user_n = 0;
    server_data->server = create_new_server(port);
    if (server_data->server == NULL)
        return NULL;
    server_data->server->state = true;
    return server_data;
}

bool server_add_user(server_data_t *server_data)
{
    user_list_t *new_user = malloc(sizeof(user_list_t) * 1);

    if (new_user == NULL)
        return FAILED;
    new_user->user_uuid = NULL;
    new_user->is_auth = false;
    new_user->user_peer =
    fetch_last_added_peer(server_data->server->network_server);
    server_data->active_users = realloc(server_data->active_users,
    sizeof(user_list_t *) * (server_data->active_user_n + 2));
    if (server_data->active_users == NULL)
        return FAILED;
    server_data->active_users[server_data->active_user_n] = new_user;
    server_data->active_user_n += 1;
    return SUCCESS;
}

void destroy_server_data(server_data_t *server_data)
{
    if (server_data == NULL)
        return;
    wrapper_destroy(server_data->wrapper);
    for (size_t i = 0; i < server_data->active_user_n; i++) {
        free(server_data->active_users[i]->user_peer);
        free(server_data->active_users[i]);
    }
    free(server_data->active_users);
    free(server_data);
}