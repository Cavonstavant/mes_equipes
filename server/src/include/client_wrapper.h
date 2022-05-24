/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** client_wrapper
*/

/// \file server/src/include/client_wrapper.h

#ifndef CLIENT_WRAPPER_H
    #define CLIENT_WRAPPER_H

    #include "net_utils.h"

/// \brief Teams core wrapper around both network and application
/// representation of an user
/// \note This structure aims to provide a link between
/// the cilent at the network level and the user at the application level
typedef struct teams_client_s {
    /// network representation of the client
    peer_t *network_client;
    /// uuid of the client
    // uuid_t app_client;
} teams_client_t;

#endif /* CLIENT_WRAPPER_H */
