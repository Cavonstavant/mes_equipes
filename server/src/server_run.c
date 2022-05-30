/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_run
*/

/// \file server/src/server_run.c

#include "server.h"
#include <signal.h>

static bool running = true;

///
/// \brief Catch the sigint signal
///
/// \param var Useless data
///
void sigint_handler(int var)
{
    running = false;
    (void) var;
}

int server_run(int port)
{
    server_data_t *server_data = init_server_data(port);

    if (server_data == NULL)
        return FAILED;
    signal(SIGINT, sigint_handler);
    server_loop(server_data);
    destroy_server_data(server_data);
    return SUCCESS;
}

void server_loop(server_data_t *server_data)
{
    tcp_server_t *network_server = server_data->server->network_server;

    server_fill_fd_sets(network_server);
    while (server_data->server->state) {
        if (server_wait(network_server) == -1)
            break;
        if (server_manage_fd_update(network_server))
            server_add_user(server_data);
        server_fill_fd_sets(network_server);
        server_data->server->state = running;
    }
}