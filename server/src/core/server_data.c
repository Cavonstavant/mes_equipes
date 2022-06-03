/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_data
*/

/// \file server/src/core/server_data.c

#include "unpack_json.h"
#include "server.h"
#include <stdlib.h>

server_data_t *init_server_data(long port)
{
    server_data_t *server_data = malloc(sizeof(server_data_t) * 1);

    if (server_data == NULL)
        return NULL;
    server_data->wrapper = unpack_json_to_wrapper("saves/server.json");
    if (server_data->wrapper == NULL)
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
    new_user->disconnected = CONNECTED;
    new_user->loc = NULL;
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

void server_remove_user(server_data_t *server_data, user_list_t *user_info)
{
    if (user_info->user_peer->pending_write == true)
        return;
    CIRCLEQ_REMOVE(&server_data->server->network_server->peers_head,
    user_info->user_peer, peers);
    close(user_info->user_peer->sock_fd);
    if (user_info->user_peer != NULL) {
        free(user_info->user_peer);
        user_info->user_peer = NULL;
    }
    user_info->disconnected = LOGOUT;
}

void remove_disconnected_user(server_data_t *server_data, user_state_t comp)
{
    for (size_t i = 0; i < server_data->active_user_n; i++) {
        if (server_data->active_users[i]->disconnected == comp)
            server_remove_user(server_data, server_data->active_users[i]);
    }
}

void destroy_server_data(server_data_t *server_data)
{
    if (server_data == NULL)
        return;
    wrapper_destroy(server_data->wrapper);
    remove_disconnected_user(server_data, CONNECTED);
    for (size_t i = 0; i < server_data->active_user_n; i++) {
        if (server_data->active_users[i]->loc != NULL)
            my_uuid_destroy(server_data->active_users[i]->loc);
        free(server_data->active_users[i]);
    }
    free(server_data->active_users);
    free(server_data);
}