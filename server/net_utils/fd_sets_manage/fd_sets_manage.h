/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** fd_sets_managep
*/

/// \file server/net_utils/fd_sets_manage/server_accept_new_client.ca

#ifndef FD_SETS_MANAGE_H
#define FD_SETS_MANAGE_H

    #include "net_utils.h"

bool server_accept_new_client(tcp_server_t *srv);
bool server_read_client(tcp_server_t *srv, peer_t *tmp);
bool server_write_client(tcp_server_t *srv, peer_t *tmp);
bool server_close_client(tcp_server_t *srv, peer_t *tmp);

#endif /* FD_SETS_MANAGE_H */
