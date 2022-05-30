/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** my_teams_server
*/

/// \file server/src/core/my_teams_server.c

#include "my_teams_server.h"
#include "fd_set_manage.h"

/*void teams_server_run(teams_server_t *self)
{
    tcp_server_t *network_srv = self->network_server;

    server_fill_fd_sets(network_srv);
    while (self->state) {
        server_wait(network_srv);
        if (server_manage_fd_update(network_srv))
            self->add_user(self, fetch_last_added_peer(self->network_server));
        server_fill_fd_sets(network_srv);
        remove_disconnected_clients(self);
    }
}*/

teams_server_t *create_new_server(long port)
{
    teams_server_t *new_server = malloc(sizeof(teams_server_t));

    if (!new_server) {
        TEAMS_LOG("malloc: Failed to create new tcp server");
        return NULL;
    }
    new_server->network_server = create_tcp_server(port);
    if (!new_server->network_server)
        return NULL;
    return new_server;
}