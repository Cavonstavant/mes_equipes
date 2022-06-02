/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_201
*/

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>

void client_201_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    response->data.data.user_info_data.user_uuid =
        strtok(response->message, ":");
    response->data.data.user_info_data.user_name = strtok(NULL, ":");
    client_event_logged_in(response->data.data.user_info_data.user_uuid,
        response->data.data.user_info_data.user_name);
    fflush(NULL);
}