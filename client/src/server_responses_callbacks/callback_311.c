/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_311
*/

/// \file client/src/server_responses_callbacks/callback_311.c

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/// \brief Lists uuid prefixes.
static const char *uuid_prefixes[] = {
    "CHA",
    "NULL",
    "THR",
    "TEM",
    NULL
};

/// \brief Find user response type.
/// \param response The server response.
/// \return true if the response is a user response, false otherwise.
static bool user_response_type(char *response)
{
    if (strncmp(response, "/send", 5) == 0
        || strncmp(response, "/messages", 9) == 0
        || strncmp(response, "/user", 5) == 0)
        return true;
    return false;
}

/// \brief Find team response type.
/// \param The server response.
/// \return true if the response is a team response, false otherwise.
static bool team_response_type(char *response)
{
    if (strncmp(response, "/subscribe", 10) == 0
        || strncmp(response, "/unsubscribe", 12) == 0
        || strncmp(response, "/subscribed", 11) == 0)
        return true;
    return false;
}

/// \brief Manage use command.
/// \param response The server response.
static void manage_use_command(char *response)
{
    strtok(NULL, ":");
    strtok(NULL, ":");
    if (strncmp(response, uuid_prefixes[0], 3) == 0) {
        client_error_unknown_channel(strtok(NULL, ":"));
        return;
    }
    if (strncmp(response, uuid_prefixes[1], 3) == 0) {
        client_error_unknown_team(strtok(NULL, ":"));
        return;
    }
    if (strncmp(response, uuid_prefixes[2], 3) == 0) {
        client_error_unknown_thread(strtok(NULL, ":"));
        return;
    }
}

void client_311_response_callback(void *data)
{
    server_response_t *response = (server_response_t *)data;

    if (!response || !response->message)
        return;
    response->message = strchr(response->message, ' ') + 1;
    if (user_response_type(response->message)){
        strtok(NULL, ":");
        client_error_unknown_user(strtok(NULL, ":"));
        return;
    }
    if (team_response_type(response->message)){
        strtok(NULL, ":");
        client_error_unknown_team(strtok(NULL, ":"));
        return;
    }
    if (strncmp(response->message, "/use", 5))
        manage_use_command(response->message + 5);
}
