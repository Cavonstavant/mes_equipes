/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** fetch_message
*/

/// \file client/client_net_utils/fetch_message.c

#include "client_utils.h"
#include <string.h>
#include <unistd.h>

char *fetch_message(client_net_server_t *server)
{
    char *msg;
    ssize_t read_size = 0;

    if (!server)
        return NULL;
    server->pending_read = true;
    read_size = read(server->sock_fd, server->pending_read, MAX_MSG);
    if (read_size < 0) {
        TEAMS_LOG("Internal Server Error: read\n");
        return NULL;
    }
    if (read_size == 0) {
        TEAMS_LOG("Connection to the server lost\n");
        return NULL;
    }
    msg = strndup(server->read_buffer, strlen(server->read_buffer));
    return msg;
}