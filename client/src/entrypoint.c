/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** entrypoint
*/

/// \file client/src/entrypoint.c

#include <stdio.h>
#include <stdlib.h>
#include "teams_client.h"
#include "client_utils.h"

static const char *usage = "USAGE: %s ip port\n \
\tip\tis the server ip address on which the server socket listens \
\tport\tis the port number on which the server socket listens\n";

int main(int ac, char **av)
{
    teams_client_t *server;

    if (ac != 3) {
        printf(usage, av[0]);
        return 84;
    }
    if (ac == 3 && (strcmp(av[1], "--help") | strcmp(av[1], "-h")) == 0) {
        printf(usage, av[0]);
        return 0;
    }
    if (!(server = teams_client_create(av[1], atol(av[2]))))
        return 84;
    server->run(server);
    server->stop(server);
    return 0;
}
