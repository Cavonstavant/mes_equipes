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
    printf("JE RENTRE DANS LE SELECT\n");
    fflush(NULL);
    if (select(FD_SETSIZE, &server->read_fds,
        &server->write_fds, NULL, NULL) == -1){
        TEAMS_LOG("Internal Server Error: select\n");
        return;
    }
    printf("JE SORS DU SELECT\n");
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
    if (FD_ISSET(0, &server->read_fds)) {
        printf("JE CALL GETLINE\n");
        char *msg = NULL;
        //ssize_t getline_size = 0;
        size_t msg_size = 0;
        getline(&msg, &msg_size, stdin);
        printf("J'ai lu : %s\n", msg);
    }
}
