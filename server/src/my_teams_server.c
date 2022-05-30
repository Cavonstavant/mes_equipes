/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** my_teams_server
*/

/// \file server/src/my_teams_server.c

#include "my_teams_server.h"
#include "fd_set_manage.h"
#include "client_wrapper.h"

void teams_server_run(teams_server_t *self)
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
}

void teams_server_stop(teams_server_t *self)
{
    teams_client_t *client = NULL;
    teams_client_t *tmp = NULL;

    if (!self)
        return;
    CIRCLEQ_FOREACH(client, &self->clients, clients) {
        tmp = client;
        client = CIRCLEQ_NEXT(client, clients);
        CIRCLEQ_REMOVE(&self->clients, tmp, clients);
        free(tmp->network_client);
        free(tmp);
    }
}

/// \brief init the teams server methods
static void init_teams_server_methods(teams_server_t *new_server)
{
    new_server->run = teams_server_run;
    new_server->stop = teams_server_stop;
    new_server->add_user = teams_server_add_user;
}

teams_server_t *create_new_server(long port, char *save_pathname)
{
    teams_server_t *new_server = malloc(sizeof(teams_server_t));

    if (!new_server) {
        TEAMS_LOG("malloc: Failed to create new tcp server");
        return NULL;
    }
    if (!(new_server->save_pathname = strdup(save_pathname))) {
        TEAMS_LOG("strdup: ");
        return NULL;
    }
    new_server->network_server = create_tcp_server(port);
    if (!new_server->network_server) {
        free(new_server->save_pathname);
        return NULL;
    }
    CIRCLEQ_INIT(&new_server->clients);
    init_teams_server_methods(new_server);
    return new_server;
}