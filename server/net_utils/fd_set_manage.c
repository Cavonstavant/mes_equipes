/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** fd_set_manage
*/

/// \file server/net_utils/fd_set_manage.c

#include "net_utils.h"

void restore_fd_sets(fd_set *read_fds, fd_set *write_fds,
    fd_set *read_save, fd_set *write_save)
{
    FD_ZERO(read_fds);
    FD_ZERO(write_fds);
    *read_fds = *read_save;
    *write_fds = *write_save;
}

void fill_fd_sets(tcp_server_t *srv)
{
    fd_set tmp_rdfs, tmp_wdfs;
    peer_t *tmp = NULL;

    tmp_rdfs = srv->read_fds;
    tmp_wdfs = srv->write_fds;
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