/*
** EPITECH PROJECT, 2022
** Project
** File description:
** upper_component_adding_test
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "upper_component_adding.h"

Test(objects_my_wrapper, add_user) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_user(my_wrapper, (user_creation_t) {
        "My_comment",
        true

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->user_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_users) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_user(my_wrapper, (user_creation_t) {
        "My_comment",
        true

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_user(my_wrapper, (user_creation_t) {
        "My_comment",
        true

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->user_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_team) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_team(my_wrapper, (team_creation_t) {
        "My_comment",
        "Desc"

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->team_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_teams) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_team(my_wrapper, (team_creation_t) {
        "My_comment",
        "Desc"

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_team(my_wrapper, (team_creation_t) {
        "My_comment",
        "Desc"

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->team_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_conversation) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_conversation(my_wrapper, (conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->conversation_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_conversations) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_conversation(my_wrapper, (conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_conversation(my_wrapper, (conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->conversation_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_thread) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_thread(my_wrapper, (thread_creation_t) {
        "Title",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->thread_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_threads) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_thread(my_wrapper, (thread_creation_t) {
        "Title",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_thread(my_wrapper, (thread_creation_t) {
        "Title",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->thread_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_channel) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_channel(my_wrapper, (channel_creation_t) {
       "Title",
       "Desc",
       my_uuid_init(TEM_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->channel_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_channels) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_channel(my_wrapper, (channel_creation_t) {
       "Title",
       "Desc",
       my_uuid_init(TEM_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_channel(my_wrapper, (channel_creation_t) {
       "Title",
       "Desc",
       my_uuid_init(TEM_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->channel_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}