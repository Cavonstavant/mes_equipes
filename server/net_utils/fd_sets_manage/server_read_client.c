/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** server_read_client
*/

#include "net_utils.h"

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
    return (true);
}
