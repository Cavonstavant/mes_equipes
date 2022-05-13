/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** fd_set_manage
*/

/// \file server/net_utils/fd_set_manage.c

#include "net_utils.h"
#include <sys/time.h>

void server_fill_fd_sets(tcp_server_t *srv)
{
    peer_t *tmp = NULL;

    FD_ZERO(&srv->read_fds);
    FD_ZERO(&srv->write_fds);
    CIRCLEQ_FOREACH(tmp, &srv->peers_head, peers) {
        if (tmp->pending_command)
            FD_SET(tmp->sock_fd, &srv->read_fds);
        if (tmp->pending_write)
            FD_SET(tmp->sock_fd, &srv->write_fds);
    }
    FD_SET(srv->sock_fd, &srv->read_fds);
}