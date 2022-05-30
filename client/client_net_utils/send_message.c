/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** send_message
*/

/// \file client/client_net_utils/send_message.c

#include "client_utils.h"
#include <string.h>
#include <unistd.h>

bool send_message(client_net_server_t *server, const char *msg)
{
    if (!server || !msg)
        return false;
    if (strlen(msg) == 0)
        return false;
    strcpy(server->output_buffer, msg);
    if (server->connected)
        write(server->sock_fd, server->output_buffer, strlen(msg));
    return true;
}