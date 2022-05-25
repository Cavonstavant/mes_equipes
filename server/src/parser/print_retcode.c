/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** print_retcode
*/

#include "rcodes.h"
#include <stdio.h>

void print_retcode(int code, char **args)
{
    retcodes_t *retcode = create_new_repcode(code);

    printf(retcode->repr);
    free(retcode);
}
