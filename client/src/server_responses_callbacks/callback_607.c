/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_607
*/

/// \file client/src/server_responses_callbacks/callback_607.c

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
    if (!(resp->data.data.thread_response_data.thread_uuid
        = strtok(msg, ":")))
        return;
    if (!(resp->data.data.thread_response_data.user_uuid
        = strtok(NULL, ":")))
        return;
    if (!(resp->data.data.thread_response_data.creation_time
        = strtok(NULL, ":")))
        return;
    if (!(resp->data.data.thread_response_data.thread_title
        = strtok(NULL, ":")))
        return;
    if (!(resp->data.data.thread_response_data.thread_body
        = strtok(NULL, ":")))
        return;
}

/// \brief Call the client api.
/// \param res The server response.
static void call_api(server_response_t *res)
{
    if (!res)
        return;
    client_event_thread_created(
        res->data.data.thread_response_data.thread_uuid + 4,
        res->data.data.thread_response_data.user_uuid + 4,
        res->data.data.thread_response_data.creation_time,
        res->data.data.thread_response_data.thread_title,
        res->data.data.thread_response_data.thread_body);
}

void client_607_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    update_response_data(response, response->message);
    call_api(response);
    update_response_data(response, NULL);
    while (response->data.data.event_data.user_uuid
        && response->message) {
        call_api(response);
        fflush(NULL);
        update_response_data(response, NULL);
    }
}
