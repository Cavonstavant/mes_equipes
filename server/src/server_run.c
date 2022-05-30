/*
** EPITECH PROJECT, 2022
** Project
** File description:
** server_run
*/

/// \file server/src/server_run.c

#include "server.h"

int server_run(int port)
{
    server_data_t *server_data = init_server_data(port);

    if (server_data == NULL)
        return FAILED;
    /// CALL THE NETWORK LOOP AND PARSER :)
    destroy_server_data(server_data);
    return SUCCESS;
}