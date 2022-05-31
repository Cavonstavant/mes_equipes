/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_wrapper_to_json
*/

#include "object_wrapper.h"
#include <stdio.h>
#include <stdbool.h>

void channel_to_json(channel_t *channel, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", channel->uuid->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", channel->name);
    fprintf(file, "\"Description\":\"%s\",", channel->description);
    fprintf(file, "\"Parent\":\"%s\",", channel->team->uuid.repr);
    fprintf(file, "\"Child\":[");
    for (int i = 0; i < channel->threads_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"},", channel->threads[i]->uuid.repr);
    }
    fprintf(file, "]}");
}

void comment_to_json(comment_t *comment, FILE *file)
{
    char time_display[20];

    fprintf(file, "{\"UUID\":\"%s\",", comment->uuid->uuid.repr);
    fprintf(file, "\"Parent\":\"%s\",", comment->thread->uuid.repr);
    fprintf(file, "\"Author\":\"%s\",", comment->author->uuid.repr);
    fprintf(file, "\"Body\":\"%s\",", comment->body);
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&comment->time));
    fprintf(file, "\"Time\":\"%s\"}", time_display);
}

void conversation_to_json(conversation_t *conversation, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", conversation->uuid->uuid.repr);
    fprintf(file, "\"Participants\":[");
    for (int i = 0; i < conversation->participant_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}",
        conversation->participant[i]->uuid.repr);
        if (i + 1 < conversation->participant_n)
            fprintf(file, ",");
    }
    fprintf(file, "],\"Messages\":[");
    for (int i = 0; i < conversation->message_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"},",
        conversation->messages[i]->uuid.repr);
        if (i + 1 < conversation->message_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void message_to_json(message_t *message, FILE *file)
{
    char time_display[20];

    fprintf(file, "{\"UUID\":\"%s\",", message->uuid->uuid.repr);
    fprintf(file, "\"Body\":\"%s\",", message->body);
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&message->time));
    fprintf(file, "\"Time\":\"%s\"}", time_display);
}

void team_to_json(team_t *team, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", team->uuid->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", team->name);
    fprintf(file, "\"Description\":\"%s\",", team->description);
    fprintf(file, "\"Channels\":[");
    for (int i = 0; i < team->channel_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", team->channels[i]->uuid.repr);
        if (i + 1 < team->channel_n)
            fprintf(file, ",");
    }
    fprintf(file, "],\"Users\":[");
    for (int i = 0; i < team->user_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", team->users[i]->uuid.repr);
        if (i + 1 < team->user_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void thread_to_json(thread_t *thread, FILE *file)
{
    char time_display[20];

    fprintf(file, "{\"UUID\":\"%s\",", thread->uuid->uuid.repr);
    fprintf(file, "\"Parent\":\"%s\",", thread->channel->uuid.repr);
    fprintf(file, "\"Author\":\"%s\",", thread->author->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", thread->name);
    fprintf(file, "\"Body\":\"%s\",", thread->body);
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&thread->date));
    fprintf(file, "\"Time\":\"%s\",", time_display);
    fprintf(file, "\"Comments\":[");
    for (int i = 0; i < thread->comment_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", thread->comments[i]->uuid.repr);
        if (i + 1 < thread->comment_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void user_to_json(user_t *user, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", user->uuid->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", user->name);
    fprintf(file, "\"Status\":\"%s\",",
    ((user->status == ONLINE) ? "online" : "offline"));
    fprintf(file, "\"Teams\":[");
    for (int i = 0; i < user->team_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", user->teams[i]->uuid.repr);
        if (i + 1 < user->team_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void pack_wrapper_to_json_channel(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "{\"Channel number\":%i,\"Channels\":[", wrapper->channel_n);
    for (int i = 0; i < wrapper->channel_n; i++) {
        channel_to_json(wrapper->channels[i], file);
        if (i + 1 < wrapper->channel_n)
            fprintf(file, ",");
    }
}

void pack_wrapper_to_json_comment(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Comment number\":%i,\"Comments\":[",
    wrapper->channel_n);
    for (int i = 0; i < wrapper->comment_n; i++) {
        comment_to_json(wrapper->comments[i], file);
        if (i + 1 < wrapper->comment_n)
            fprintf(file, ",");
    }
}

void pack_wrapper_to_json_conversation(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Conversation number\":%i,\"Conversation\":[",
    wrapper->conversation_n);
    for (int i = 0; i < wrapper->conversation_n; i++) {
        conversation_to_json(wrapper->conversations[i], file);
        if (i + 1 < wrapper->conversation_n)
            fprintf(file, ",");
    }
}

void pack_wrapper_to_json_message(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Message number\":%i,\"Messages\":[",
    wrapper->message_n);
    for (int i = 0; i < wrapper->message_n; i++) {
        message_to_json(wrapper->messages[i], file);
        if (i + 1 < wrapper->message_n)
            fprintf(file, ",");
    }
}

void pack_wrapper_to_json_team(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Team number\":%i,\"Teams\":[", wrapper->team_n);
    for (int i = 0; i < wrapper->team_n; i++) {
        team_to_json(wrapper->teams[i], file);
        if (i + 1 < wrapper->team_n)
            fprintf(file, ",");
    }
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

void pack_wrapper_to_json_user(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"User number\":%i,\"Users\":[", wrapper->user_n);
    for (int i = 0; i < wrapper->user_n; i++) {
        user_to_json(wrapper->users[i], file);
        if (i + 1 < wrapper->user_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

bool pack_wrapper_to_json(object_wrapper_t *wrapper)
{
    FILE *file = fopen("server.json", "w+");

    if (!file || !wrapper)
        return false;
    pack_wrapper_to_json_channel(wrapper, file);
    pack_wrapper_to_json_comment(wrapper, file);
    pack_wrapper_to_json_conversation(wrapper, file);
    pack_wrapper_to_json_message(wrapper, file);
    pack_wrapper_to_json_team(wrapper, file);
    pack_wrapper_to_json_thread(wrapper, file);
    pack_wrapper_to_json_user(wrapper, file);
    fclose(file);
    return true;
}
