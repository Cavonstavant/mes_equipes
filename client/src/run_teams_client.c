/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** run_teams_client
*/

/// \file client/src/run_teams_client.c

#include "client_utils.h"
#include "teams_client.h"
#include <stdio.h>
#include <stdlib.h>

/// \brief Prints the usage of the client
/// \param server the client net server
/// \param serv the teams client
static void print_message(client_net_server_t *server, teams_client_t *serv)
{
    char *msg = NULL;

    if (server->pending_read && server->connected) {
        if (!(msg = fetch_message(server)))
            exit(0);
        printf("%s", msg);
        fflush(NULL);
        serv->prompt_display = true;
        if (strncmp(msg, "203", 3) == 0)
            exit(0);
        free(msg);
    }
}

void run_teams_client(teams_client_t *server)
{
    client_net_server_t *net_server = server->net_srv;

    while (net_server->connected) {
        if (!net_server->connected) {
            printf("Connection to the server lost\n");
            break;
        }
        if (server->prompt_display) {
            server->prompt_display = false;
            printf("> ");
            fflush(NULL);
        }
        update_client(net_server);
        print_message(net_server, server);
    }
}
