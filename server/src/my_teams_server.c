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
    teams_client_t *tmp = NULL;

    server_fill_fd_sets(network_srv);
    while (self->state) {
        server_wait(network_srv);
        if (server_manage_fd_update(network_srv))
            self->add_user(self, fetch_last_added_peer(self->network_server));
        CIRCLEQ_FOREACH(tmp, self, clients)
            if (tmp->network_client->pending_read)
                printf("%s", fetch_message(tmp->network_client));
    }
}

void teams_server_stop(teams_server_t *self)
{
    (void) self;
}

static void init_teams_server_methods(teams_client_t *srv)
{
    new_server->run = teams_server_run;
    new_server->stop = teams_server_stop;
    new_server->add_user = teams_server_add_user;
}

teams_server_t *create_new_server(long port, char *save_pathname)
{
    teams_server_t *new_server = malloc(sizeof(teams_server_t));
    (void) save_pathname;

    if (!new_server) {
        TEAMS_LOG("malloc: Failed to create new tcp server");
        return NULL;
    }
    if (!(new_server->save_pathname = strdup(save_pathname))) {
        TEAMS_LOG("strdup: ");
        return NULL;
    }
    new_server->network_server = create_tcp_server(port);
    init_teams_server_methods(new_server);
    return new_server;
}