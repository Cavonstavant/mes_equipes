/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** entrypoint
*/

#include <stdio.h>
#include <string.h>
#include "my_teams_server.h"

static const char *usage = "USAGE: %s port\n\n\tport is the port \
number on which the server socket listens.\n";

int main(int ac, char **av)
{
    teams_server_t *server;

    if (ac != 2){
        printf(usage, av[0]);
        return 84;
    }
    if (ac == 2 && strcmp("--help", av[1]) == 0){
        printf(usage, av[0]);
        return 0;
    }
    server = create_new_server(atol(av[1]), "my_teams.bak");
    if (!server)
        return 84;
    server->state = true;
    server->run(server);
    return (0);
}