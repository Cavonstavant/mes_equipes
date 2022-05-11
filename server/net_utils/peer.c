/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** peer
*/

#include "net_utils.h"

peer_t *new_peer(int fd, struct sockaddr_in addr)
{
    peer_t *new_peer = malloc(sizeof(peer_t));

    if (new_peer == NULL)
        HANDLE_ERROR("malloc");
    new_peer->sock_fd = fd;
    new_peer->peer_addr = addr;
    return (new_peer);
}
