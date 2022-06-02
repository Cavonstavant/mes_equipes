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

static int my_open(char *path)
{
    int fd = 0;

    if (find_str(path, ".json") < 0)
        return -1;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return -1;
    return fd;
}

object_wrapper_t *unpack_json_to_wrapper(char *path)
{
    object_wrapper_t *wrapper = wrapper_init();
    int fd = my_open(path);
    char *file_content = readfile(fd);

    if (!file_content || !wrapper)
        return NULL;
    if (!unpack_json_to_wrapper_channel(wrapper, file_content) ||
    !unpack_json_to_wrapper_team(wrapper, file_content) ||
    !unpack_json_to_wrapper_user(wrapper, file_content) ||
    !unpack_json_to_wrapper_comment(wrapper, file_content) ||
    !unpack_json_to_wrapper_conversation(wrapper, file_content) ||
    !unpack_json_to_wrapper_message(wrapper, file_content) ||
    !unpack_json_to_wrapper_thread(wrapper, file_content))
        return NULL;
    free(file_content);
    close(fd);
    return wrapper;
}
