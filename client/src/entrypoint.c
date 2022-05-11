/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** entrypoint
*/

#include <stdio.h>

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2) {
        printf("Usage: ./mes_equipes <team_name>\n");
        return (84);
    }
    return (0);
}
