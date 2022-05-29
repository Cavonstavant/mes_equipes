/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** client_utils
*/

#include "client_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// \brief juste as the function name says
static bool bind_socket(client_net_server_t *srv, long port)
{
    srv->sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (srv->sock_fd < 0){
        TEAMS_LOG("bind");
        return false;
    }
    srv->srv_addr.sin_family = AF_INET;
    srv->srv_addr.sin_port = htons(port);
    if (bind(srv->sock_fd, (struct sockaddr *) &srv->self,
        sizeof(struct sockaddr)) < 0){
        TEAMS_LOG("bind\n");
        return false;
    }
    return true;
}

client_net_server_t *create_net_server(const char *ip, long port)
{
    client_net_server_t *new_server;

    if (!(new_server = malloc(sizeof(client_net_server_t *))))
        return NULL;
    new_server->srv_addr.sin_addr = inet_addr(ip);
    if (new_server->srv_addr.sin_addr == INADDR_NONE) {
        TEAMS_LOG("inet_addr: Invalid server ip provided\n");
        return NULL;
    }
    bind_socket(new_server, port);
    return new_server;
}