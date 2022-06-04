/*
** EPITECH PROJECT, 2022
** mes_equipes
** File description:
** teams_responses
*/

/// \file client/src/include/teams_responses.h

#ifndef TEAMS_RESPONSES_H_
    #define TEAMS_RESPONSES_H_

    #define _XOPEN_SOURCE

    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

/// \defgroup teams_responses Teams responses
/// @{

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
    char *thread_uuid;
    char *sender_uuid;
    char *message_body;
    char *creation_time;
};

struct user_info_data_s {
    char *user_uuid;
    char *user_name;
    int status;
};

struct subscribe_data_s {
    char *user_uuid;
    char *team_uuid;
};

struct help_data_s {
    char *help_message;
};

struct event_data_s {
    char *user_uuid;
    char *user_name;
    char *event_message;
    char *team_uuid;
    char *thread_uuid;
};

/// @}

/// Only one type of data is allowed to be returned by a response.
typedef union server_response_data_u {
    struct team_response_data_s team_response_data;
    struct channel_response_data_s channel_response_data;
    struct thread_response_data_s thread_response_data;
    struct message_response_data_s message_response_data;
    struct user_info_data_s user_info_data;
    struct subscribe_data_s subscribe_data;
    struct help_data_s help_data;
    struct event_data_s event_data;
} server_response_internal_data_t;

/// Enum of possible responses data types.
typedef enum server_response_data_type_e {
    TEAM_RESPONSE_DATA,
    CHANNEL_RESPONSE_DATA,
    THREAD_RESPONSE_DATA,
    MESSAGE_RESPONSE_DATA,
    USER_INFO_DATA,
    SUBSCRIBE_DATA,
    HELP_DATA,
    EVENT_DATA,
    DATA_TYPE_SIZE
} server_response_data_type_t;

/// The data of a response
typedef struct server_response_data_s {

    /// \brief The type of data
    server_response_data_type_t type;

    /// \brief The data
    server_response_internal_data_t data;
} server_response_data_t;

typedef void (*server_response_callback_t)(void *);

/// \brief A response from the server.
/// \param data The data of the response.
static inline void default_response_callback(void *data)
{
    (void)data;
}

/// A response from the server
typedef struct server_response_s {

    /// \brief The code of the response.
    int code;

    /// \brief The message of the response.
    char *message;

    /// \brief The data of the response.
    server_response_data_t data;

    /// \brief The callback to call when the response is received.
    server_response_callback_t callback;
} server_response_t;

/// \brief The 201 client response callback.
/// \param data The data of the response.
void client_201_response_callback(void *data);

/// \brief The 202 client response callback.
/// \param data The data of the response.
void client_202_response_callback(void *data);

/// \brief The 203 client response callback.
/// \param data The data of the response.
void client_203_response_callback(void *data);

/// \brief The 204 client response callback.
/// \param data The data of the response.
void client_204_response_callback(void *data);

/// \brief The 205 client response callback.
/// \param data The data of the response.
void client_206_response_callback(void *data);

/// \brief The 207 client response callback.
/// \param data The data of the response.
void client_207_response_callback(void *data);

/// \brief The 208 client response callback.
/// \param data The data of the response.
void client_208_response_callback(void *data);

/// \brief The 209 client response callback.
/// \param data The data of the response.
void client_209_response_callback(void *data);

/// \brief The 210 client response callback.
/// \param data The data of the response.
void client_210_response_callback(void *data);

/// \brief The 211 client response callback.
/// \param data The data of the response.
void client_211_response_callback(void *data);

/// \brief The 212 client response callback.
/// \param data The data of the response.
void client_212_response_callback(void *data);

/// \brief The 213 client response callback.
/// \param data The data of the response.
void client_213_response_callback(void *data);

/// \brief The 214 client response callback.
/// \param data The data of the response.
void client_214_response_callback(void *data);

/// \brief The 215 client response callback.
/// \param data The data of the response.
void client_215_response_callback(void *data);

/// \brief The 216 client response callback.
/// \param data The data of the response.
void client_216_response_callback(void *data);

/// \brief The 217 client response callback.
/// \param data The data of the response.
void client_217_response_callback(void *data);

/// \brief The 218 client response callback.
/// \param data The data of the response.
void client_218_response_callback(void *data);

/// \brief The 219 client response callback.
/// \param data The data of the response.
void client_219_response_callback(void *data);

/// \brief The 220 client response callback.
/// \param data The data of the response.
void client_220_response_callback(void *data);

/// \brief The 311 client response callback.
/// \param data The data of the response.
void client_311_response_callback(void *data);

/// \brief The 321 client response callback.
/// \param data The data of the response.
void client_321_response_callback(void *data);

/// \brief The 401 client response callback.
/// \param data The data of the response.
void client_401_response_callback(void *data);

/// \brief The 601 client response callback.
/// \param data The data of the response.
void client_601_response_callback(void *data);

/// \brief The 602 client response callback.
/// \param data The data of the response.
void client_602_response_callback(void *data);

/// \brief The 603 client response callback.
/// \param data The data of the response.
void client_603_response_callback(void *data);

/// \brief The 604 client response callback.
/// \param data The data of the response.
void client_604_response_callback(void *data);

/// \brief The 605 client response callback.
/// \param data The data of the response.
// void client_605_response_callback(void *data);

/// \brief The 606 client response callback.
/// \param data The data of the response.
// void client_606_response_callback(void *data);

/// \brief The 607 client response callback.
/// \param data The data of the response.
// void client_607_response_callback(void *data);

/// Template for all the responses
static const server_response_t server_response_template[] = {
    {
        .code = 201,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data.team_response_data = {
                .team_uuid = NULL,
                .team_name = NULL,
                .team_description = NULL,
                .creation_time = NULL,
            }
        },
        .callback = client_201_response_callback
    },
    {
        .code = 202,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = client_202_response_callback
    },
    {
        .code = 203,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = client_203_response_callback
    },
    {
        .code = 204,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = client_204_response_callback
    },
    {
        .code = 206,
        .message = NULL,
        .data = {
            .type = TEAM_RESPONSE_DATA,
            .data.team_response_data = {
                .team_uuid = NULL,
                .team_name = NULL,
                .team_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_206_response_callback
    },
    {
        .code = 207,
        .message = NULL,
        .data = {
            .type = CHANNEL_RESPONSE_DATA,
            .data.channel_response_data = {
                .channel_uuid = NULL,
                .channel_name = NULL,
                .channel_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_207_response_callback
    },
    {
        .code = 208,
        .message = NULL,
        .data = {
            .type = THREAD_RESPONSE_DATA,
            .data.thread_response_data = {
                .thread_uuid = NULL,
                .user_uuid = NULL,
                .thread_title = NULL,
                .thread_body = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_208_response_callback
    },
    {
        .code = 209,
        .message = NULL,
        .data = {
            .type = MESSAGE_RESPONSE_DATA,
            .data.message_response_data = {
                .sender_uuid = NULL,
                .message_body = NULL,
                .creation_time = NULL,
                .thread_uuid = NULL
            }
        },
        .callback = client_209_response_callback
    },
    {
        .code = 210,
        .message = NULL,
        .data = {
            .type = MESSAGE_RESPONSE_DATA,
            .data.message_response_data = {
                .sender_uuid = NULL,
                .message_body = NULL,
                .creation_time = NULL,
                .thread_uuid = NULL
            }
        },
        .callback = client_210_response_callback
    },
    {
        .code = 211,
        .message = NULL,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = client_211_response_callback
    },
    {
        .code = 212,
        .message = NULL,
        .data = {
            .type = TEAM_RESPONSE_DATA,
            .data.team_response_data = {
                .team_uuid = NULL,
                .team_name = NULL,
                .team_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_212_response_callback
    },
    {
        .code = 213,
        .data = {
            .type = CHANNEL_RESPONSE_DATA,
            .data.channel_response_data = {
                .channel_uuid = NULL,
                .channel_name = NULL,
                .channel_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_213_response_callback
    },
    {
        .code = 214,
        .data = {
            .type = THREAD_RESPONSE_DATA,
            .data.thread_response_data = {
                .thread_uuid = NULL,
                .user_uuid = NULL,
                .thread_title = NULL,
                .thread_body = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_214_response_callback
    },
    {
        .code = 215,
        .data = {
            .type = TEAM_RESPONSE_DATA,
            .data.team_response_data = {
                .team_uuid = NULL,
                .team_name = NULL,
                .team_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_215_response_callback
    },
    {
        .code = 216,
        .data = {
            .type = CHANNEL_RESPONSE_DATA,
            .data.channel_response_data = {
                .channel_uuid = NULL,
                .channel_name = NULL,
                .channel_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_216_response_callback
    },
    {
        .code = 217,
        .data = {
            .type = THREAD_RESPONSE_DATA,
            .data.thread_response_data = {
                .thread_uuid = NULL,
                .user_uuid = NULL,
                .thread_title = NULL,
                .thread_body = NULL,
                .creation_time = NULL
            }
        },
        .callback = client_217_response_callback
    },
    {
        .code = 218,
        .data = {
            .type = MESSAGE_RESPONSE_DATA,
            .data.message_response_data = {
                .sender_uuid = NULL,
                .message_body = NULL,
                .creation_time = NULL,
                .thread_uuid = NULL
            }
        },
        .callback = client_218_response_callback
    },
    {
        .code = 219,
        .data = {
            .type = SUBSCRIBE_DATA,
            .data.subscribe_data = {
                .user_uuid = NULL,
                .team_uuid = NULL,
            }
        },
        .callback = client_219_response_callback
    },
    {
        .code = 220,
        .data = {
            .type = SUBSCRIBE_DATA,
            .data.subscribe_data = {
                .user_uuid = NULL,
                .team_uuid = NULL,
            }
        },
        .callback = client_220_response_callback
    },
    {
        .code = 221,
        .data = {
            .type = HELP_DATA,
            .data.help_data = {
                .help_message = NULL
            }
        },
        .callback = default_response_callback
    },
    {
        .code = 311,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = client_311_response_callback
    },
    {
        .code = 312,
        .data = {
            .type = TEAM_RESPONSE_DATA,
            .data.team_response_data = {
                .team_uuid = NULL,
                .team_name = NULL,
                .team_description = NULL,
                .creation_time = NULL
            }
        },
        .callback = default_response_callback
    },
    {
        .code = 320,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = default_response_callback
    },
    {
        .code = 401,
        .data = {
            .type = USER_INFO_DATA,
            .data.user_info_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .status = 0
            }
        },
        .callback = default_response_callback
    },
    {
        .code = 601,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_601_response_callback
    },
    {
        .code = 602,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_602_response_callback
    },
    {
        .code = 603,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_603_response_callback
    },
    {
        .code = 604,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_604_response_callback
    },
    {
        .code = 605,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_604_response_callback
    },
    {
        .code = 606,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_604_response_callback
    },
    {
        .code = 607,
        .data = {
            .type = EVENT_DATA,
            .data.event_data = {
                .user_uuid = NULL,
                .user_name = NULL,
                .event_message = NULL,
                .team_uuid = NULL,
                .thread_uuid = NULL,
            }
        },
        .callback = client_604_response_callback
    }
};

/// \brief sets the default response data fror the giver response code
/// \param data the response data to use
/// \param code the response code
/// \return true if the response code is valid, false otherwise
static inline bool memset_server_response_data(
server_response_t *data,
int code)
{
    server_response_t template;
    int i = 0;

    if (!data)
        return false;
    while (i < 31 && server_response_template[i].code != code)
        i++;
    if (i == 31)
        return false;
    template = server_response_template[i];
    data->callback = template.callback;
    data->code = template.code;
    data->data = template.data;
    return true;
}

/// \brief creates a new server response data struct
/// \param code the response code
/// \return the new server response data struct
static inline server_response_t *create_response_from_code(int code)
{
    server_response_t *data = malloc(sizeof(server_response_t));

    if (!data)
        return NULL;
    if (!memset_server_response_data(data, code)) {
        free(data);
        return NULL;
    }
    return data;
}

#endif /* !TEAMS_RESPONSES_H_ */
