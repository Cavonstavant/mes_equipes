/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_data
*/

/// \file server/src/core/server_data.c

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

void destroy_server_data(server_data_t *server_data)
{
    if (server_data == NULL)
        return;
    wrapper_destroy(server_data->wrapper);
    /// Destroy server_t
    for (size_t i = 0; i < server_data->active_user_n; i++)
        (void) server_data; /// FREE CONTENT
    free(server_data->active_users);
    free(server_data);
}