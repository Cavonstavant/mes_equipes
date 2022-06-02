/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** teams_responses
*/

#ifndef TEAMS_RESPONSES_H_
    #define TEAMS_RESPONSES_H_

    #include <stdlib.h>

struct team_response_data_s {
    char *team_uuid;
    char *team_name;
    char *team_description;
    char *creation_time;
};

struct channel_response_data_s {
    char *channel_uuid;
    char *channel_name;
    char *channel_description;
    char *creation_time;
};

struct thread_response_data_s {
    char *thread_uuid;
    char *user_uuid;
    char *thread_title;
    char *thread_body;
    char *creation_time;
};

struct message_response_data_s {
    char *sender_uuid;
    char *message_body;
    char *creation_time;
};

struct user_info_data_s {
    char *user_uuid;
    char *user_name;
};

typedef union server_response_data_u {
    struct team_response_data_s team_response_data;
    struct channel_response_data_s channel_response_data;
    struct thread_response_data_s thread_response_data;
    struct message_response_data_s message_response_data;
    struct user_info_data_s user_info_data;
} server_response_data_t;

typedef enum server_response_data_type_e {
    TEAM_RESPONSE_DATA,
    CHANNEL_RESPONSE_DATA,
    THREAD_RESPONSE_DATA,
    MESSAGE_RESPONSE_DATA,
    USER_INFO_DATA,
    DATA_TYPE_SIZE
} server_response_data_type_t;

typedef struct server_response_data_s {
    server_response_data_type_t type;
    server_response_data_t data;
} server_response_data_t;

typedef void (*server_response_data_callback_t)(server_response_data_t *);

typedef struct server_response_s {
    int code;
    char *message;
    server_response_data_t data;
    server_response_data_callback_t callback;
} server_response_t;

static const server_response_t server_response_template[] = {
    {
        .code = 201,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data = {
                .team_response_data = {
                    .user_uuid = NULL,
                    .user_name = NULL
                }
            }
        },
        .callback = NULL
    },
    {
        .code = 202,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data = {
                .team_response_data = {
                    .user_uuid = NULL,
                    .user_name = NULL
                }
            }
        },
        .callback = NULL
    },
    {
        .code = 203,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data = {
                .team_response_data = {
                    .user_uuid = NULL,
                    .user_name = NULL
                }
            }
        },
        .callback = NULL
    }
};

#endif /* !TEAMS_RESPONSES_H_ */
