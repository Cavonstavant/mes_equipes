/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_run
*/

/// \file server/src/server_run.c

#include "server.h"
#include "fd_set_manage.h"
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

void process_command_inspection(server_data_t *server_data)
{
    tcp_server_t *srv = server_data->server->network_server;
    peer_t *tmp = NULL;

    CIRCLEQ_FOREACH(tmp, &srv->peers_head, peers) {
        if (tmp->pending_read == true)
            printf("Peer tell : %s\n", fetch_message(tmp)); /// CALL PARSER
    }
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
        process_command_inspection(server_data);
        server_fill_fd_sets(network_server);
        server_data->server->state = running;
    }
}