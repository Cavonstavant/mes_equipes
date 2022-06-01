/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json
*/

#ifndef UNPACK_JSON_H_
#define UNPACK_JSON_H_

#include "object_wrapper.h"

int get_balise_number(char *file, int channel_nb, char *balise);
char *get_balise_content(char *file, int channel_nb, char *balise);
void unpack_json_to_wrapper_channel(object_wrapper_t *wrapper, char *file);
void unpack_json_to_wrapper_team(object_wrapper_t *wrapper, char *file);
int find_str(char *file, char *to_find);
char *readfile(int fd);

#endif /* !UNPACK_JSON_H_ */
