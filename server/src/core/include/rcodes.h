/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** rcodes
*/

/// \file server/src/core/include/rcodes.h

#ifndef RCODES_H_
    #define RCODES_H_

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "fd_set_manage.h"

/// \brief The retcodes_s structure contains the representation of the return
/// code as char *, an int which represent the return code, and a array of
/// char * which contains the arguments to be used.
typedef struct retcodes_s {
    char *repr;
    int code;
    char **params;
} retcodes_t;

static const retcodes_t retcodes[] = {
    {.repr = "200 Success\n",
    .code = 200,
    .params = NULL},
    {.repr = "201 Successfully connected to existing used: %s\n",
    .code = 201,
    .params = NULL},
    {.repr =
    "202 Successfully connected, new user created with username: %s\n",
    .code = 202,
    .params = NULL},
    {.repr = "203 Successfully disconnected as user: %s\n",
    .code = 203,
    .params = NULL},
    {.repr = "310 No requested data found, empty relation\n",
    .code = 310,
    .params = NULL},
    {.repr = "311 Reqested UUID: %s not found\n",
    .code = 311,
    .params = NULL},
    {.repr = "312 Requested username: %s not found\n",
    .code = 312,
    .params = NULL},
    {.repr = "320 Invalid action: Data already exist\n",
    .code = 320,
    .params = NULL},
    {.repr = "321 Invalid action: Already subscribed to %s\n",
    .code = 321,
    .params = NULL},
    {.repr = "322 Invalid action: Not subscribed to %s\n",
    .code = 322,
    .params = NULL},
    {.repr = "401 Invalid requested action, please login\n",
    .code = 401,
    .params = NULL},
    {.repr = "500 Syntax error\n",
    .code = 500,
    .params = NULL},
    {.repr = "501 Format error: Invalid UUID\n",
    .code = 501,
    .params = NULL},
    {.repr = "502 Format error: body too long\n",
    .code = 502,
    .params = NULL},
    {.repr = "503 Format error: name too long\n",
    .code = 503,
    .params = NULL},
    {.repr = "504 Format error: description too long\n",
    .code = 504,
    .params = NULL},
    {.repr = "510 Syntax error: Wrong number of arguments\n",
    .code = 510,
    .params = NULL},
    {.repr = "520 Syntax error: Invalid format\n",
    .code = 520,
    .params = NULL},
    {.repr = "530 Syntax error: Command not found\n",
    .code = 530,
    .params = NULL},
    {.repr = "540 Syntax error: Not implemented\n",
    .code = 540,
    .params = NULL},
    {0, 0, 0}
};

/// \brief Get a retcodes_t structure depending on the code passed as
/// parameter.
/// \param int The code to be send.
/// \return A new instance of retcodes_t.
static inline retcodes_t *create_new_repcode(int code) {
    retcodes_t *retcode = (retcodes_t *) malloc(sizeof(retcodes_t));

    if (!retcode)
        return NULL;
    for (int i = 0; retcodes[i].repr; i++) {
        if (retcodes[i].code == code) {
            memcpy(retcode, &retcodes[i], sizeof(retcodes_t));
            return retcode;
        }
    }
    free(retcode);
    return NULL;
}

/// \brief Print the message code depending on the code passed as parameter.
/// \param int The return code value.
/// \param char **Arguments to be passed to the retcodes_t structure if it is
/// necessary.
static inline void print_retcode(int code, char *arg, peer_t *peer)
{
    retcodes_t *retcode = create_new_repcode(code);
    char *command = malloc(sizeof(char) * ((arg) ? strlen(arg) +
    strlen(retcode->repr) - 1 : strlen(retcode->repr)));

    if (command == NULL)
        return;
    if (arg)
        sprintf(command, retcode->repr, arg);
    else
        sprintf(command, retcode->repr);
    client_set_output_buffer(peer, command);
    free(command);
    free(retcode);
}

#endif /* !RCODES_H_ */
