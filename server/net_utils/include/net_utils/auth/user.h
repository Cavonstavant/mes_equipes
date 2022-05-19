/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** user
*/

/// \file server/net_utils/include/net_utils/auth/user.h

#ifndef USER_H
    #define USER_H

    #include <unistd.h>
    #include <sys/queue.h>
    #include <stdbool.h>

/// \brief Represents a user from the application side
typedef struct user_s {

    /// The user's login
    char *username;

    /// The user's password
    char *password;

    /// True if the user is logged in false if not
    bool logged_in;

    /// \brief A pointer to the next/prev user
    CIRCLEQ_ENTRY(user_s) users;
} user_t;

/// \brief Represents the auth status
enum authentification_e {
    /// Authentication success
    AUTH_OK,

    /// Authentication failed
    AUTH_FAILED,

    /// User not found
    AUTH_USER_NOT_FOUND,
};

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
enum authentification_e authenticate_user(struct users_head users,
char *uname,
char *passwd);

#endif /* USER_H */
