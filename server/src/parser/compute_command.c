/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

static void free_args(char **args)
{
    int index = 0;

    while (args[index]) {
        free(args[index]);
        index++;
    }
    free(args);
}

int compute_command(const char *command)
{
    char **args = split_command(command);

    free_args(args);
    return (0);
}
