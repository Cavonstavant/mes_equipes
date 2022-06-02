/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_thread_to_json
*/

/// \file objects/wrapper/src/pack_wrapper/pack_thread_to_json.c
/// \brief Pack a thread into a json file

#include "pack_json.h"

/// \brief Pack a thread into a json file
/// \param thread The thread to pack
/// \param file The file to write the thread into
static void thread_to_json(thread_t *thread, FILE *file)
{
    char time_display[20];

    fprintf(file, "{\"THR_UUID\":\"%s\",", thread->uuid->uuid.repr);
    fprintf(file, "\"THR_Parent\":\"%s\",", thread->channel->uuid.repr);
    fprintf(file, "\"THR_Author\":\"%s\",", thread->author->uuid.repr);
    fprintf(file, "\"THR_Name\":\"%s\",", thread->name);
    fprintf(file, "\"THR_Body\":\"%s\",", thread->body);
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&thread->date));
    fprintf(file, "\"THR_Time\":\"%s\",", time_display);
    fprintf(file, "\"THR_Comment number\":%i,\"THR_Comments\":[",
    thread->comment_n);
    for (int i = 0; i < thread->comment_n; i++) {
        fprintf(file, "{\"THR_COM_UUID\":\"%s\"}",
        thread->comments[i]->uuid.repr);
        if (i + 1 < thread->comment_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void pack_wrapper_to_json_thread(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Thread number\":%i,\"Threads\":[", wrapper->thread_n);
    for (int i = 0; i < wrapper->thread_n; i++) {
        thread_to_json(wrapper->threads[i], file);
        if (i + 1 < wrapper->thread_n)
            fprintf(file, ",");
    }
}
