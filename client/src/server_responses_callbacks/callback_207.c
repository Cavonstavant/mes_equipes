/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_207
*/

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>

static void update_response_data(server_response_t *resp, char *msg)
{
    if (!resp)
        return;
    resp->data.data.channel_response_data.channel_uuid = strtok(msg, ":");
    if (!resp->data.data.channel_response_data.channel_uuid)
        return;
    resp->data.data.channel_response_data.channel_name = strtok(NULL, ":");
    if (!resp->data.data.channel_response_data.channel_name)
        return;
    resp->data.data.channel_response_data.channel_description =
        strtok(NULL, ":");
}

void client_207_response_callback(void *data)
{
    server_response_t *resp = (server_response_t *)data;

    if (!resp || !resp->message)
        return;
    resp->message = strchr(resp->message, ' ') + 1;
    update_response_data(resp, resp->message);
    client_print_channel(resp->data.data.channel_response_data.channel_uuid + 4,
        resp->data.data.channel_response_data.channel_name,
        resp->data.data.channel_response_data.channel_description);
    update_response_data(resp, NULL);
    while (resp->data.data.channel_response_data.channel_uuid
        && resp->message) {
        client_print_channel(
            resp->data.data.channel_response_data.channel_uuid + 4,
            resp->data.data.channel_response_data.channel_name,
            resp->data.data.channel_response_data.channel_description);
        fflush(NULL);
        update_response_data(resp, NULL);
    }
}