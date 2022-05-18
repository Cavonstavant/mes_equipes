/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** server_write_client
*/

#include "net_utils.h"

bool client_set_output_buffer(peer_t *tmp, char const *message)
{
    if (!tmp || !buffer)
        return (false);
    if (strlen(buffer) > MAX_MSG)
        return (false);
    strcpy(tmp->output_buffer, buffer);
    tmp->pending_write = true;
    return (true);
}


bool server_write_client(tcp_server_t *srv, peer_t *tmp)
{
    ssize_t write_size;
    size_t msg_size;

    if (!srv || !tmp)
        return (false);
    if ((msg_size = strlen(tmp->output_buffer)) <= 0) {
        TEAMS_LOG("Internal Error: empty output buffer.\n");
        return (false);
    }
    if ((write_size = write(tmp->sock_fd, tmp->output_buffer, msg_size)) < 0){
        TEAMS_LOG("write\n");
        return (false);
    }
    if (write_size != (ssize_t)msg_size) {
        TEAMS_LOG("Internal Error: could not write all the message.\n");
        return (false);
    }
    tmp->pending_write = false;
    return (true);
}
