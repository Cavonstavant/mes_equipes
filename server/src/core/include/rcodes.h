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

    /// \brief char * The name of the return code.
    char *repr;

    /// \brief int The return code.
    int code;

    /// \brief char ** The arguments of the return code.
    char **params;
} retcodes_t;

/// \brief The retcodes_s structure contains the representation of the return
static const retcodes_t retcodes[] = {
    {.repr = "200 Success\n",
    .code = 200,
    .params = NULL},
    {.repr = "201 Successfully connected to existing user:%s",
    .code = 201,
    .params = NULL},
    {.repr =
    "202 Successfully connected, new user created with username:%s",
    .code = 202,
    .params = NULL},
    {.repr = "203 Successfully disconnected as user:%s",
    .code = 203,
    .params = NULL},
    {.repr = "204 %s",
    .code = 204,
    .params = NULL},
    {.repr = "206 %s",
    .code = 206,
    .params = NULL},
    {.repr = "207 %s",
    .code = 207,
    .params = NULL},
    {.repr = "208 %s",
    .code = 208,
    .params = NULL},
    {.repr = "209 %s",
    .code = 209,
    .params = NULL},
    {.repr = "210 %s",
    .code = 210,
    .params = NULL},
    {.repr = "211 %s",
    .code = 211,
    .params = NULL},
    {.repr = "212 %s",
    .code = 212,
    .params = NULL},
    {.repr = "213 %s",
    .code = 213,
    .params = NULL},
    {.repr = "214 %s",
    .code = 214,
    .params = NULL},
    {.repr = "215 %s",
    .code = 215,
    .params = NULL},
    {.repr = "216 %s",
    .code = 216,
    .params = NULL},
    {.repr = "217 %s",
    .code = 217,
    .params = NULL},
    {.repr = "218 %s",
    .code = 218,
    .params = NULL},
    {.repr = "219 %s",
    .code = 219,
    .params = NULL},
    {.repr = "220 %s",
    .code = 220,
    .params = NULL},
    {.repr = "221 %s",
    .code = 221,
    .params = NULL},
    {.repr = "310 No requested data found, empty relation\n",
    .code = 310,
    .params = NULL},
    {.repr = "311 %s",
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
static inline retcodes_t *create_new_repcode(int code)
{
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
static inline bool print_retcode(int code, char *arg, peer_t *peer, bool res)
{
    retcodes_t *retcode = create_new_repcode(code);
    char *command = malloc(sizeof(char) * ((arg) ? strlen(arg) +
    strlen(retcode->repr) - 1 : strlen(retcode->repr) + 1));

    if (command == NULL)
        return res;
    if (arg)
        sprintf(command, retcode->repr, arg);
    else
        sprintf(command, retcode->repr);
    client_set_output_buffer(peer, command);
    free(command);
    free(retcode);
    return res;
}

/// \brief Compute all the rcodes args to a char *
/// \param param Args to compute
/// \return char* Newly created string
static inline char *cretcodes(char **param)
{
    int size = 0;
    char *res = NULL;
    int total_size = 0;

    for (; param[size] != NULL; size++);
    for (int i = 0; i < size; i++)
        total_size += strlen(param[i]);
    res = malloc(sizeof(char) * (total_size + 2 * size));
    if (res == NULL)
        return NULL;
    res[0] = '\0';
    for (int i = 0; i < size - 1; i++) {
        strcat(res, param[i]);
        res[strlen(res) + 1] = '\0';
        res[strlen(res)] = ':';
    }
    strcat(res, param[size - 1]);
    strcat(res, "\n");
    return res;
}

#endif /* !RCODES_H_ */
