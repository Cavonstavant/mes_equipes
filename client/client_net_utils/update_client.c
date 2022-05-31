/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** update_server
*/

/// \file client/client_net_utils/update_server.c

#include "client_utils.h"
#include "internals.h"

void update_client(client_net_server_t *server)
{
    fill_fd_sets(server);
    if (select(1, &server->read_fds, &server->write_fds, NULL, NULL) == -1){
        TEAMS_LOG("Internal Server Error: select\n");
        return;
    }
    if (FD_ISSET(server->sock_fd, &server->read_fds))
        server->pending_read = true;
    if (FD_ISSET(server->sock_fd, &server->write_fds))
        server->pending_write = true;
    if (FD_ISSET(server->sock_fd, &server->err_fds)){
        TEAMS_LOG("Internal Server Error: Failed to connect\n");
        server->connected = false;
    }
    printf("server->pending_read: %d\n", server->pending_read);
    printf("server->pending_write: %d\n", server->pending_write);
}
