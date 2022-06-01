/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** teams_client
*/

#ifndef TEAMS_CLIENT_H
    #define TEAMS_CLIENT_H

    #include "client_utils.h"

/// \brief Wraps the appplication and network sidde of the teams server
typedef struct teams_client_s {
    /// The network layer, imported from client_net_utils
    client_net_server_t *net_srv;

    /// Runs a connected client by sending and
    /// receiving messages to the associated server
    void (*run)(struct teams_client_s *);

    /// Stop a connected client and destroy all associated ressources
    void (*stop)(struct teams_client_s *);

    /// Display prompt
    bool prompt_display;
} teams_client_t;

/// \brief Initializes the teams client with the given ip and port
/// \param ip The dotted, null terminated ip address of the server
/// \param port The port number of the server
/// \return A pointer to the teams client
/// or NULL if the connection to the server failed
teams_client_t *teams_client_create(const char *ip, long port);

/// \brief Runs a connected client by sending and
/// receiving messages to the associated server
void run_teams_client(teams_client_t *server);

/// \brief Stop a connected client and destroy all associated ressources
void stop_teams_client(teams_client_t *server);

#endif /* TEAMS_CLIENT_H */
