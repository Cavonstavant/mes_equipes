/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** server_read_client
*/

#include "net_utils.h"

char *fetch_message(peer_t *peer)
{
    if (!peer)
        return (NULL);
    if (!peer->pending_read)
        return (NULL);
    peer->pending_read = false;
    return (strdup(peer->output_buffer));
}

bool server_read_client(tcp_server_t *srv, peer_t *tmp)
{
    if (!tmp && !srv)
        return (false);
    ssize_t read_size;

    read_size = read(tmp->sock_fd, tmp->input_buffer, MAX_MSG);
    if (read_size < 0){
        TEAMS_LOG("read");
        return (false);
    }
    if (read_size == 0){
        TEAMS_LOG("Client disconnected");
        return (false);
    }
    tmp->pending_read = true;
    return (true);
}
