/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_user
*/



void unpack_json_to_wrapper_user(object_wrapper_t *wrapper, char *file)
{
    int user_nbr = get_balise_number(file, 0, "\"User number\":");

    for (int i = 0; i < user_nbr; i++) {
        create_new_user(wrapper, file, i);
    }
}
