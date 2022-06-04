/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_206
*/

/// \file client/src/server_responses_callbacks/callback_206.c

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>

/// \brief Update response data callback.
/// \param resp The server response.
/// \param msg The message to parse.
static void update_response_data(server_response_t *resp, char *msg)
{
    if (!resp)
        return;
    resp->data.data.team_response_data.team_uuid = strtok(msg, ":");
    if (!resp->data.data.team_response_data.team_uuid)
        return;
    resp->data.data.team_response_data.team_name = strtok(NULL, ":");
    if (!resp->data.data.team_response_data.team_name)
        return;
    resp->data.data.team_response_data.team_description = strtok(NULL, ":");
}

void client_206_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    update_response_data(response, response->message);
    client_print_teams(response->data.data.team_response_data.team_uuid + 4,
        response->data.data.team_response_data.team_name,
        response->data.data.team_response_data.team_description);
    update_response_data(response, NULL);
    while (response->data.data.team_response_data.team_uuid
        && response->message) {
        client_print_teams(
            response->data.data.team_response_data.team_uuid + 4,
            response->data.data.team_response_data.team_name,
            response->data.data.team_response_data.team_description);
        fflush(NULL);
        update_response_data(response, NULL);
    }
}
