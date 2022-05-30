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

#endif /* !SERVER_H_ */
