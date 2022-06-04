/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** run_teams_client
*/

/// \file client/src/run_teams_client.c

#include "client_utils.h"
#include "teams_client.h"
#include "teams_responses.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// \brief Get the code from the response.
/// \param response The response to get the code from.
/// \return The code from the response.
static int get_code_from_response(char *response)
{
    char *tmp;
    char *code;
    int code_int;

    if (!(tmp = strdup(response)))
        return -1;
    if (!(code = strtok(tmp, " ")))
        return -1;
    code_int = atoi(code);
    return code_int;
}

/// \brief Display a syntax error
/// \param msg The response from the server
static void print_syntax_error(char *msg)
{
    printf("\033[0;4mError:\n\t\033[0m");
    printf("\033[1;31m%s\033[0m", msg);
}

/// \brief Management of the response from the server.
/// \param msg The response from the server and callbacks.
static void manage_response(char *msg)
{
    server_response_t *response = NULL;
    int code = -1;

    code = get_code_from_response(msg);
    if (code >= 500)
        print_syntax_error(msg);
    if (!(response = create_response_from_code(code)))
        return;
    response->message = msg;
    if (code >= 300) {
        printf("\033[0;4mError:\n\t\033[0m");
        printf("\033[1;31m%s\033[0m\n\n", msg);
    } else
        printf("\033[0;4mServer answer:\033[0m\n\t\033[1;32m%s\033[0m\n\n",
        msg);
    response->callback(response);
    if (code == 203)
        exit(0);
}

/// \brief Prints the usage of the client
/// \param server the client net server
/// \param serv the teams client
static void print_message(client_net_server_t *server, teams_client_t *serv)
{
    char *msg = NULL;

    if (server->pending_read && server->connected){
        if (!(msg = fetch_message(server)))
            exit(0);
        serv->prompt_display = true;
        manage_response(msg);
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
