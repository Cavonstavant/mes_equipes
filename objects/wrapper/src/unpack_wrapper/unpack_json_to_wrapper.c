/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper
*/

#include "pack_json.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "object_uuid.h"
#include "unpack_json.h"

object_wrapper_t *unpack_json_to_wrapper(void)
{
    object_wrapper_t *wrapper = wrapper_init();
    int fd = open("server.json", O_RDONLY);
    char *file_content = readfile(fd);

    if (!file_content || !wrapper)
        return NULL;
    unpack_json_to_wrapper_channel(wrapper, file_content);
    unpack_json_to_wrapper_team(wrapper, file_content);
    // unpack_json_to_wrapper_user(wrapper, file_content);
    // wrapper = unpack_json_to_wrapper_comment(wrapper, file);
    // wrapper = unpack_json_to_wrapper_conversation(wrapper, file);
    // wrapper = unpack_json_to_wrapper_message(wrapper, file);
    // wrapper = unpack_json_to_wrapper_thread(wrapper, file);
    close(fd);
    return wrapper;
}
