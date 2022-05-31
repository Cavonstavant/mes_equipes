/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** manage_fd_sets
*/

#include "internals.h"

void fill_fd_sets(client_net_server_t *server)
{
    if (!server)
        return;
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->err_fds);
    if (!server->pending_read)
        FD_SET(server->sock_fd, &server->read_fds);
    if (server->pending_write)
        FD_SET(server->sock_fd, &server->write_fds);
}