/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** update_server
*/

/// \file client/client_net_utils/update_server.c

#include "client_utils.h"
#include "internals.h"
#include <fcntl.h>

static bool check_for_disconnection(client_net_server_t *server)
{
    if (!(fcntl(server->sock_fd, F_GETFD) != -1 || errno != EBADF)) {
        server->connected = false;
        return (true);
    }
    return (false);
}

void update_client(client_net_server_t *server)
{
    if (check_for_disconnection(server))
        return;
    fill_fd_sets(server);
    if (select(FD_SETSIZE, &server->read_fds,
        &server->write_fds, NULL, NULL) == -1){
        TEAMS_LOG("Internal Server Error: select\n");
        return;
    }
    if (FD_ISSET(server->sock_fd, &server->read_fds))
        server->pending_read = true;
    if (FD_ISSET(server->sock_fd, &server->write_fds)) {
        send_message(server);
        update_client(server);
    }
    if (FD_ISSET(server->sock_fd, &server->err_fds)){
        TEAMS_LOG("Internal Server Error: Failed to connect\n");
        server->connected = false;
    }
}
