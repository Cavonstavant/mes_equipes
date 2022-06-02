/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_comment_to_json
*/

#include "pack_json.h"

static void comment_to_json(comment_t *comment, FILE *file)
{
    char time_display[20];

    fprintf(file, "{\"COM_UUID\":\"%s\",", comment->uuid->uuid.repr);
    fprintf(file, "\"COM_Parent\":\"%s\",", comment->thread->uuid.repr);
    fprintf(file, "\"COM_Author\":\"%s\",", comment->author->uuid.repr);
    fprintf(file, "\"COM_Body\":\"%s\",", comment->body);
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&comment->time));
    fprintf(file, "\"COM_Time\":\"%s\"}", time_display);
}

void pack_wrapper_to_json_comment(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Comment number\":%i,\"Comments\":[",
    wrapper->comment_n);
    for (int i = 0; i < wrapper->comment_n; i++) {
        comment_to_json(wrapper->comments[i], file);
        if (i + 1 < wrapper->comment_n)
            fprintf(file, ",");
    }
}
