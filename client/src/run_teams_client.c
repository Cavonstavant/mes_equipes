/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** run_teams_client
*/

#include "client_utils.h"
#include "teams_client.h"
#include <stdio.h>
#include <stdlib.h>

static void print_message(client_net_server_t *server)
{
    char *msg = NULL;

    if (server->pending_read) {
        if (!(msg = fetch_message(server)))
            return;
        printf("%s\n", msg);
        if (strncmp(msg, "203", 3) == 0)
            exit(0);
        free(msg);
    }
}

static void send_message_to_server(client_net_server_t *server)
{
    char *msg = NULL;
    ssize_t getline_size = 0;
    size_t msg_size = 0;

    printf("> ");
    fflush(stdin);
    getline_size = getline(&msg, &msg_size, stdin);
    if (getline_size == -1)
        return;
    set_output_buffer(server, msg);
    free(msg);
}

void run_teams_client(teams_client_t *server)
{
    client_net_server_t *net_server = server->net_srv;

    while (net_server->connected) {
        send_message_to_server(net_server);
        if (!net_server->connected){
            printf("Connection to the server lost\n");
            break;
        }
        update_client(net_server);
        print_message(net_server);
    }
}