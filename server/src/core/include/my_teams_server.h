/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** my_teams_server
*/

/// \file server/src/core/include/my_teams_server.h

#ifndef MY_TEAMS_SERVER_H
    #define MY_TEAMS_SERVER_H

    #include "net_utils.h"
    #include <stdlib.h>
    #include <stdbool.h>

/// \brief Wraps the application and network side of the teams srever
typedef struct teams_server_s {

    /// The network layer, imported from net_utils
    tcp_server_t *network_server;

    /// Represents the state of the server (running 1, stopped 0)
    bool state;
} teams_server_t;

/// \brief creates a new teams server
/// \param port The port the server will listen to
/// \return The newly created server
teams_server_t *create_new_server(long port);

#endif /* MY_TEAMS_SERVER_H */
