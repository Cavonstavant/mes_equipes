/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_interaction_tests
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"

Test(objects_my_wrapper, interaction_comment) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_comment_to_thread(my_wrapper, (comment_creation_t) {
        "Comments",
        my_uuid_init(USR_),
        my_uuid_init(TEM_)
    }, my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_thread(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    temp = wrapper_new_comment_to_thread(my_wrapper, (comment_creation_t) {
        "Comments",
        my_uuid_init(USR_),
        my_uuid_init(TEM_)
    },  my_wrapper->threads[0]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->comment_n, 1);
}

Test(objects_my_wrapper, interaction_thread) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_thread_to_channel(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    }, my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_channel(my_wrapper, (channel_creation_t) {
        "Chan",
       "Desc",
       my_uuid_init(TEM_)
    });

    temp = wrapper_new_thread_to_channel(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    },  my_wrapper->channels[0]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->thread_n, 1);
}

Test(objects_my_wrapper, interaction_channel) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_channel_to_team(my_wrapper, (channel_creation_t) {
        "Chan",
       "Desc",
       my_uuid_init(TEM_)
    }, my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_team(my_wrapper, (team_creation_t) {
        "My_team",
        "Desc"
    });

    temp = wrapper_new_channel_to_team(my_wrapper, (channel_creation_t) {
        "Chan",
       "Desc",
       my_uuid_init(TEM_)
    },  my_wrapper->teams[0]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->channel_n, 1);
}

Test(objects_my_wrapper, interaction_conversation) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_conversation_to_user(my_wrapper, (conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)
    }, my_uuid_init(TEM_), my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_user(my_wrapper, (user_creation_t) {
        "Constant",
        true
    });

    wrapper_adding_user(my_wrapper, (user_creation_t) {
        "Constant",
        true
    });

    temp = wrapper_new_conversation_to_user(my_wrapper, (conversation_creation_t) {
       my_uuid_init(USR_),
        my_uuid_init(USR_)
    },  my_wrapper->users[0]->uuid, my_wrapper->users[1]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->conversation_n, 1);
}

Test(objects_my_wrapper, interaction_message) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_message_to_conversation(my_wrapper, (message_creation_t) {
        "Chan"
    }, my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_conversation(my_wrapper, (conversation_creation_t) {
        my_uuid_init(TEM_),
       my_uuid_init(TEM_)
    });

    temp = wrapper_new_message_to_conversation(my_wrapper, (message_creation_t) {
        "Chan"
    },  my_wrapper->conversations[0]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->message_n, 1);
}