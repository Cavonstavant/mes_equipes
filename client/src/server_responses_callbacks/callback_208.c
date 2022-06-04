
/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_208
*/

/// \file client/src/server_responses_callbacks/callback_208.c

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
    struct tm temp = {0};

    if (!res)
        return;
    strptime(
        res->data.data.thread_response_data.creation_time,
        "%Y-%m-%d %H-%M-%S",
        &temp);
    client_channel_print_threads(
        res->data.data.thread_response_data.thread_uuid + 4,
        res->data.data.thread_response_data.user_uuid + 4,
        mktime(&temp),
        res->data.data.thread_response_data.thread_title,
        res->data.data.thread_response_data.thread_body);
}

void client_208_response_callback(void *data)
{
    server_response_t *resp = (server_response_t *)data;

    if (!resp || !resp->message)
        return;
    resp->message = strchr(resp->message, ' ') + 1;
    update_response_data(resp, resp->message);
    call_api(resp);
    update_response_data(resp, NULL);
    while (resp->data.data.thread_response_data.thread_uuid
        && resp->message) {
        call_api(resp);
        update_response_data(resp, NULL);
    }
}
