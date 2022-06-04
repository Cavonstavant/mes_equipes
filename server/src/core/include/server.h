/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server
*/

/// \file server/src/core/include/server.h

#ifndef SERVER_H_
    #define SERVER_H_

    #include "object_wrapper.h"
    #include "my_teams_server.h"

    /// \brief Return value when operation success
    #define SUCCESS 0

    /// \brief Return value when operation failed
    #define FAILED 84

extern volatile bool *server_state;

/// \brief Enumeration of the different states of the server
typedef enum user_state_e {
    CONNECTED,
    TO_LOGOUT,
    LOGOUT
} user_state_t;

/// \brief Node of a user list
typedef struct user_list_s {
    /// Uuid of the user object
    my_uuid_t *user_uuid;
    /// Peer of the network client
    peer_t *user_peer;
    /// State of the client
    bool is_auth;
    /// Login status
    user_state_t disconnected;
    /// Localisation of user
    my_uuid_t *loc;
} user_list_t;

/// \brief Major data for the server
typedef struct server_data_s {
    /// Object wrapper of the Object lib
    object_wrapper_t *wrapper;
    /// Network instance of NetUtils
    teams_server_t *server;
    /// List of all the active users
    user_list_t **active_users;
    /// Size of the list
    size_t active_user_n;
} server_data_t;

/// \brief Init and run the server
/// \param port Port of the server
/// \return int Return code
int server_run(int port);

/// \brief Init the server data structure
/// \param port Port to setup the serveur
/// \return server_data_t* Newly created server_data
server_data_t *init_server_data(long port);

/// \brief Destroy the server_data
/// \param server_data Server_data to destroy
void destroy_server_data(server_data_t *server_data);

/// \brief The server global loop
/// \param server_data The server data info
void server_loop(server_data_t *server_data);

/// \brief Add a new user to the server data
/// \param server_data Server data info
/// \return true When operation success
/// \return false When operation failed
bool server_add_user(server_data_t *server_data);

/// \brief Cross all the peer_t list and get pending read
/// \param server_data Server data
void process_command_inspection(server_data_t *server_data);

/// \brief Get the user list by peer object
/// \param server_data Server data info
/// \param peer Peer to match
/// \return user_list_t* User list matched, NULL otherwise
user_list_t *get_user_list_by_peer(server_data_t *server_data,
peer_t *peer);

/// \brief Remove a user from the connection list
/// \param server_data Server data info
/// \param user_info User info
void server_remove_user(server_data_t *server_data, user_list_t *user_info);

/// \brief Remove all the disconnected user
/// \param server_data Server data info
/// \param comp Value to compare the state connexion
void remove_disconnected_user(server_data_t *server_data, user_state_t comp);

///
/// \brief Send a event to a user uuid
///
/// \param serv Server informations
/// \param user User informations
/// \param code Rcode to call
/// \param args Arguments of the rcode
///
void send_user_event(server_data_t *serv, my_uuid_t *user, int code,
char **args);

///
/// \brief Send a event to all connected and authentified users
///
/// \param serv Server informations
/// \param code Rcode to call
/// \param args Arguments of the rcode
///
void send_users_event(server_data_t *serv, int code, char **args);

///
/// \brief Send a event to all connected and authentified users exclude current
///
/// \param serv Server informations
/// \param code Rcode to call
/// \param args Arguments to call
/// \param sock Socket to skip
///
void send_users_event_logout(server_data_t *serv, int code, char **args,
int sock);

///
/// \brief Send a event to all users exclude current
///
/// \param serv Serverinformations
/// \param code Rcode to call
/// \param args Arguments to call
///
void send_users_event_team(server_data_t *serv, int *info, char **args);

///
/// \brief Send a event to all users for object creation
///
/// \param serv Serveur informations
/// \param parent Parent uuid
/// \param code Rcode to call
/// \param args Arguments to call
///
void send_users_event_create(server_data_t *serv, my_uuid_t *parent,
int *infos, char **args);

#endif /* !SERVER_H_ */
