/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_209
*/

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>

static void update_response_data(server_response_t *resp, char *msg)
{
    if (!resp)
        return;
    if (!(resp->data.data.message_response_data.thread_uuid
        = strtok(msg, ":")))
        return;
    if (!(resp->data.data.message_response_data.sender_uuid
        = strtok(msg, ":")))
        return;
    if (!(resp->data.data.message_response_data.creation_time
        = strtok(msg, ":")))
        return;
    if (!(resp->data.data.message_response_data.message_body
        = strtok(NULL, ":")))
        return;
}

static void call_api(server_response_t *res)
{
    if (!res)
        return;
    client_thread_print_replies(
        res->data.data.message_response_data.thread_uuid + 4,
        res->data.data.message_response_data.sender_uuid + 4,
        strtol(res->data.data.message_response_data.creation_time, NULL, 10),
        res->data.data.message_response_data.message_body);
}


void client_209_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    update_response_data(response, response->message);
    call_api(response);
    update_response_data(response, NULL);
    while (response->data.data.message_response_data.thread_uuid
        && response->message) {
        call_api(response);
        fflush(NULL);
        update_response_data(response, NULL);
    }
}