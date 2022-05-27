/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** client_wrapper
*/

#include "client_wrapper.h"
#include "my_teams_server.h"

/// \todo create a new client at application side and put the uuid insde
/// new_client.uuid
teams_client_t teams_server_add_user(teams_server_t *self, peer_t *new_peer)
{
    teams_client_t new_client;

    new_client.network_client = new_peer;
    return new_client;
}