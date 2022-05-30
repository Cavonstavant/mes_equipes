/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** entrypoint
*/

/// \file server/src/entrypoint.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "entrypoint.h"

static const char *usage = "USAGE: %s port\n\n\tport is the port \
number on which the server socket listens.\n";

int main(int ac, char **av)
{
    if (ac != 2) {
        printf(usage, av[0]);
        return 84;
    }
    if (ac == 2 && strcmp("--help", av[1]) == 0){
        printf(usage, av[0]);
        return 0;
    }
    return (server_run(atol(av[1])));
}