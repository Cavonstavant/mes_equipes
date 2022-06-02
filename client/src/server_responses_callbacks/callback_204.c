/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_204
*/

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>

static void update_response_data(server_response_t *response, char *msg)
{
    if (!response)
        return;
    response->data.data.user_info_data.user_uuid = strtok(msg, ":");
    if (!response->data.data.user_info_data.user_uuid)
        return;
    response->data.data.user_info_data.user_name = strtok(NULL, ":");
    if (!response->data.data.user_info_data.user_name)
        return;
    response->data.data.user_info_data.status = atoi(strtok(NULL, ":"));
}

void client_204_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    update_response_data(response, response->message);
    client_print_users(response->data.data.user_info_data.user_uuid + 4,
        response->data.data.user_info_data.user_name,
        response->data.data.user_info_data.status);
    update_response_data(response, NULL);
    while (response->data.data.user_info_data.user_uuid
        && response->message) {
        client_print_users(
            response->data.data.user_info_data.user_uuid + 4,
            response->data.data.user_info_data.user_name,
            response->data.data.user_info_data.status);
        fflush(NULL);
        update_response_data(response, NULL);
    }
}