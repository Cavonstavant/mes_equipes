/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** peer
*/

/// \file server/net_utils/peer.c

#include "net_utils.h"

peer_t *new_peer(int fd, struct sockaddr_in addr)
{
    peer_t *new_peer = malloc(sizeof(peer_t));

    if (new_peer == NULL)
        TEAMS_LOG("malloc");
    bzero(new_peer, sizeof(peer_t));
    new_peer->sock_fd = fd;
    new_peer->peer_addr = addr;
    return (new_peer);
}
