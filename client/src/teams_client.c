/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** teams_client
*/

/// \file client/src/teams_client.c

#include "teams_client.h"
#include <stdlib.h>

/// \brief Initializes the teams client methods
/// \param server the teams client
static void init_client_methods(teams_client_t *server)
{
    server->run = run_teams_client;
    server->stop = stop_teams_client;
}

teams_client_t *teams_client_create(const char *ip, long port)
{
    teams_client_t *client = malloc(sizeof(teams_client_t));

    if (!client)
        return NULL;
    client->net_srv = create_net_server(ip, port);
    if (!client->net_srv)
        return NULL;
    init_client_methods(client);
    client->net_srv->connected = true;
    client->prompt_display = true;
    return client;
}
