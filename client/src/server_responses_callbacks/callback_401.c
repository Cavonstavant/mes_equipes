/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** callback_401
*/

#include "teams_responses.h"
#include "logging_client.h"
#include <stdio.h>

void client_401_response_callback(void *data __attribute__((unused)))
{
    client_error_unauthorized();
}
