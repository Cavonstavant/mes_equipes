/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_run
*/

/// \file server/src/core/server_run.c

#include "server.h"

int server_run(int port)
{
    server_data_t *server_data = init_server_data(port);

    if (server_data == NULL)
        return FAILED;
    server_loop(server_data);
    /// CALL THE NETWORK LOOP AND PARSER :)
    destroy_server_data(server_data);
    return SUCCESS;
}

void server_loop(server_data_t *server_data)
{
    tcp_server_t *network_server = server_data->server->network_server;

    server_fill_fd_sets(network_server);
    while (server_data->server->state) {
        server_wait(network_server);
        server_manage_fd_update(network_server);
        server_fill_fd_sets(network_server);
    }
}