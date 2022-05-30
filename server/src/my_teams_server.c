/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** my_teams_server
*/

/// \file server/src/my_teams_server.c

#include "my_teams_server.h"
#include "fd_set_manage.h"

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