/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** fd_set_manage
*/

#ifndef FD_SET_MANAGE_H
#define FD_SET_MANAGE_H

    #include "net_utils.h"

/// \brief Accepts a new client
bool server_accept_new_client(tcp_server_t *srv);

/// \brief Reads an incoming message from a client,
/// fills the peer_t::input_buffer
bool server_read_client(tcp_server_t *srv, peer_t *tmp);

/// \brief Writes a message to a client,
/// uses the peer_t::output_buffer
bool server_write_client(tcp_server_t *srv, peer_t *tmp);

/// \brief Closes a connection to a client
bool server_close_client(tcp_server_t *srv, peer_t *tmp);

#endif /* FD_SET_MANAGE_H */