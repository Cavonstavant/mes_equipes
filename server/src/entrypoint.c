/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** entrypoint
*/

#include "server.h"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    server_run(100);
    return (0);
}