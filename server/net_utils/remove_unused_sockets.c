/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** display_utils
*/

#include "net_utils.h"

void remove_unused_sockets(struct peers_head *peers, int tbr[FD_SETSIZE])
{
    peer_t *peer = CIRCLEQ_FIRST(peers);

    while (peer != (void *)peers) {
        if (tbr[peer->sock_fd] == 1) {
            CIRCLEQ_REMOVE(peers, peer, peers);
            tbr[peer->sock_fd] = 0;
        } else
            peer = CIRCLEQ_NEXT(peer, peers);
    }
}
