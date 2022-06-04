/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_213
*/

/// \file client/src/server_responses_callbacks/callback_213.c

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
    if (!(resp->data.data.channel_response_data.channel_uuid
        = strtok(msg, ":")))
        return;
    if (!(resp->data.data.channel_response_data.channel_name
        = strtok(NULL, ":")))
        return;
    if (!(resp->data.data.channel_response_data.channel_description
        = strtok(NULL, ":")))
        return;
}

/// \brief Call the client api.
/// \param res The server response.
static void call_api(server_response_t *res)
{
    if (!res)
        return;
    client_print_channel(
        res->data.data.channel_response_data.channel_uuid + 4,
        res->data.data.channel_response_data.channel_name,
        res->data.data.channel_response_data.channel_description);
}

void client_213_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    update_response_data(response, response->message);
    call_api(response);
    update_response_data(response, NULL);
    while (response->data.data.channel_response_data.channel_uuid
        && response->message) {
        call_api(response);
        fflush(NULL);
        update_response_data(response, NULL);
    }
}
