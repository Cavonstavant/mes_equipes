/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** update_server
*/

/// \file client/client_net_utils/update_server.c

#include "client_utils.h"

void udpate_server(client_net_server_t *server)
{
    FD_SET(server->sock_fd, &server->read_fds);
    select(1, &server->read_fds, &server->write_fds, NULL, NULL);
    if (FD_ISSET(server->sock_fd, &server->read_fds))
        server->pending_read = true;
    if (FD_ISSET(server->sock_fd, &server->write_fds))
        server->pending_write = true;
    if (FD_ISSET(server->sock_fd, &server->err_fds))
        server->connected = false;
}
