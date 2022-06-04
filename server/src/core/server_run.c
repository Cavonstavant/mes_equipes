/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_run
*/

/// \file server/src/core/server_run.c

#include "pack_json.h"
#include "server.h"
#include "fd_set_manage.h"
#include "parser.h"
#include <signal.h>

volatile bool *server_state = NULL;

/// \brief Catch the sigint signal
/// \param var Useless data
void sigint_handler(int var __attribute__((unused)))
{
    *server_state = false;
}

int server_run(int port)
{
    server_data_t *server_data = init_server_data(port);

    if (server_data == NULL)
        return FAILED;
    signal(SIGINT, sigint_handler);
    server_loop(server_data);
    pack_wrapper_to_json(server_data->wrapper, "saves/server.json");
    destroy_server_data(server_data);
    return SUCCESS;
}

user_list_t *get_user_list_by_peer(server_data_t *server_data,
peer_t *peer)
{
    for (size_t i = 0; i < server_data->active_user_n; i++)
        if (server_data->active_users[i]->user_peer == peer)
            return server_data->active_users[i];
    return NULL;
}

void process_command_inspection(server_data_t *server_data)
{
    tcp_server_t *srv = server_data->server->network_server;
    peer_t *tmp = NULL;

    CIRCLEQ_FOREACH(tmp, &srv->peers_head, peers) {
        if (tmp->pending_read == true)
            compute_command(fetch_message(tmp),
            get_user_list_by_peer(server_data, tmp), server_data);
    }
}

void server_loop(server_data_t *server_data)
{
    tcp_server_t *network_server = server_data->server->network_server;

    server_fill_fd_sets(network_server);
    server_state = &server_data->server->state;
    while (server_data->server->state) {
        if (server_wait(network_server) == -1)
            break;
        if (server_manage_fd_update(network_server))
            server_add_user(server_data);
        process_command_inspection(server_data);
        remove_disconnected_user(server_data, TO_LOGOUT);
        server_fill_fd_sets(network_server);
    }
}
