/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server
*/

/// \file server/include/server.h

#ifndef SERVER_H_
    #define SERVER_H_

    #include "object_wrapper.h"

    #define SUCCESS 0

    #define FAILED 84

///
/// \brief Node of a user list
///
typedef struct user_list_s {
    /// Uuid of the user object
    my_uuid_t *user_uuid;
    /// peer_t *user_peer;
} user_list_t;

///
/// \brief Major data for the server
///
typedef struct server_data_s {
    /// Object wrapper of the Object lib
    object_wrapper_t *wrapper;
    /// List of all the active users
    user_list_t **active_users;
    /// Size of the list
    size_t active_user_n;
} server_data_t;

///
/// \brief Init and run the server
///
/// \param port Port of the server
/// \return int Return code
///
int server_run(int port);

///
/// \brief Init the server data structure
///
/// \param port Port to setup the serveur
/// \return server_data_t* Newly created server_data
///
server_data_t *init_server_data(long port);

///
/// \brief Destroy the server_data
///
/// \param server_data Server_data to destroy
///
void destroy_server_data(server_data_t *server_data);

#endif /* !SERVER_H_ */
