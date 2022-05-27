/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** my_teams_server
*/

/// \file server/src/include

#ifndef MY_TEAMS_SERVER_H
    #define MY_TEAMS_SERVER_H

    #include "net_utils.h"
    #include "client_wrapper.h"
    #include <stdlib.h>
    #include <stdbool.h>

/// \brief Wraps the application and network side of the teams srever
typedef struct teams_server_s {

    /// The network layer, imported from net_utils
    tcp_server_t *network_server;

    /// Runs the server, waits on new connection an process incoming messages
    void (*run)(struct teams_server_s *self);

    /// Stop the server, create a backup file and
    /// destroy all associated ressources
    void (*stop)(struct teams_server_s *self);

    /// Save the server status into the pathname given when instanciated
    char* (*save)(struct teams_server_s *self);

    /// \copydoc teams_server_add_user
    void (*add_user)(struct teams_server_s *self, peer_t *new_peer);

    /// Stores the server configuration file location
    char *save_pathname;

    /// Represents the state of the server (running 1, stopped 0)
    bool state;

    /// The collection of clients
    struct teams_client_head clients;
} teams_server_t;

/// \brief creates a new teams server
/// \param port The port the server will listen to
/// \param save_path The path to the backup file
teams_server_t *create_new_server(long port, char *save_pathname);

/// \copydoc server_run
void teams_server_run(teams_server_t *self);

/// \brief Stop the server, create a backup file and
/// destroy all associated ressources
/// \todo create a backup file in a known format
/// \todo destroy application side ressources
void teams_server_stop(teams_server_t *self);

/// \brief create a user and adds it to the list of clients
/// \param peer the new peer created by the network library
/// \note the peer is created after recieving a new connection and
/// the validation on of the parser.
/// A new client is then added to the application side
void teams_server_add_user(teams_server_t *self, peer_t *new_peer);

/// \brief Remove any disconnected peer from the list of clients
/// \param self the teams server containing the collection of clients
void remove_disconnected_clients(teams_server_t *self);

#endif /* MY_TEAMS_SERVER_H */
