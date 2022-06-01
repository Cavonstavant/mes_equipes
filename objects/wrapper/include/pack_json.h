/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** packer_json
*/

#ifndef PACKER_JSON_H_
    #define PACKER_JSON_H_

    #include "object_wrapper.h"
    #include <stdio.h>

bool pack_wrapper_to_json(object_wrapper_t *wrapper);
void pack_wrapper_to_json_channel(object_wrapper_t *wrapper, FILE *file);
void pack_wrapper_to_json_conversation(object_wrapper_t *wrapper, FILE *file);
void pack_wrapper_to_json_message(object_wrapper_t *wrapper, FILE *file);
void pack_wrapper_to_json_team(object_wrapper_t *wrapper, FILE *file);
void pack_wrapper_to_json_user(object_wrapper_t *wrapper, FILE *file);
void pack_wrapper_to_json_thread(object_wrapper_t *wrapper, FILE *file);
void pack_wrapper_to_json_comment(object_wrapper_t *wrapper, FILE *file);

object_wrapper_t *unpack_json_to_wrapper(void);

#endif /* !PACKER_JSON_H_ */
