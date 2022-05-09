/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** check_command
*/

int check_parser(char **arguments)
{
    for (int index = 0; arguments[index]; index++) {
        printf("%s\n", arguments[index]);
    }
    return (0);
}
