/*
** EPITECH PROJECT, 2022
** mon_FTP
** File description:
** user
*/

/// \file src/server/auth/user.c

#include "net_utils/auth/user.h"
#include <stdlib.h>
#include <string.h>

user_t *create_user(char *username, char *password)
{
    user_t *user = malloc(sizeof(user_t));

    if (!user)
        return (NULL);
    user->username = (username ? strdup(username) : NULL);
    user->password = (password ? strdup(password) : NULL);
    user->logged_in = false;
    return (user);
}

bool authenticate_user(struct users_head users, char *uname, char *passwd)
{
    user_t *user = NULL;

    CIRCLEQ_FOREACH(user, &users, users) {
        if (strcmp(user->username, uname) == 0 &&
            strcmp(user->password, passwd) == 0)
            return (true);
    }
    return (false);
}
