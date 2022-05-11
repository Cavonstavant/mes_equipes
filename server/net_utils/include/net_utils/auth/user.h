/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** user
*/

/// \file src/net_utils/include/net_utils/auth/user.h

#ifndef USER_H
    #define USER_H

    #include <unistd.h>
    #include <sys/queue.h>
    #include <stdbool.h>

typedef struct user_s {
    char *username;
    char *password;
    bool logged_in;
    CIRCLEQ_ENTRY(user_s) users;
} user_t;

/// \brief Initializes a circular queue of users
CIRCLEQ_HEAD(users_head, user_s);

/// \brief Creates a new user with an username and a password
/// \param username the username of the user
/// \param password the password of the user
/// \return a new user_t
/// \warning The password is inserted 'as is' in the user_t
user_t *create_user(char *username, char *password);

/// \brief Authenticates a user
/// \param users the users collection to authenticate against
/// \param username the username of the user
/// \param password the password of the user
/// \return true or false depending on the authentication result
bool authenticate_user(struct users_head users, char *uname, char *passwd);

#endif /* USER_H */
