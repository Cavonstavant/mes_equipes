/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** client_wrapper
*/

/// \file server/src/client_wrapper.c

#include "client_wrapper.h"
#include "my_teams_server.h"

void remove_disconnected_clients(teams_server_t *self)
{
    teams_client_t *client = CIRCLEQ_FIRST(&self->clients);
    teams_client_t *tmp = NULL;

    while (client != (void*)&self->clients) {
        if (client->network_client->connected == false) {
            tmp = client;
            client = CIRCLEQ_NEXT(client, clients);
            CIRCLEQ_REMOVE(&self->clients, tmp, clients);
            free(tmp->network_client);
            free(tmp);
        } else
            client = CIRCLEQ_NEXT(client, clients);
    }
}

/// \todo create a new client at application side and put the uuid insde
/// new_client.uuid
void teams_server_add_user(teams_server_t *self, peer_t *new_peer)
{
    teams_client_t *new_client = malloc(sizeof(teams_client_t));

    if (!new_client){
        TEAMS_LOG("malloc: Failed to create new client");
        return;
    }
    new_client->network_client = new_peer;
    CIRCLEQ_INSERT_HEAD(&self->clients, new_client, clients);
}