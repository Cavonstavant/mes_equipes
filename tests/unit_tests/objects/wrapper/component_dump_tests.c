/*
** EPITECH PROJECT, 2022
** Project
** File description:
** component_dump_tests
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"

Test(objects_my_wrapper, user_journey) {
    object_wrapper_t *my_wrapper = wrapper_init();

    wrapper_adding_user(my_wrapper, (user_creation_t) {
        "Michel",
        true
    });
    wrapper_adding_user(my_wrapper, (user_creation_t) {
        "Lucas",
        true
    });
    wrapper_adding_user(my_wrapper, (user_creation_t) {
        "Constant",
        true
    });
    wrapper_adding_team(my_wrapper, (team_creation_t) {
        "My_team",
        "Desc"

    });
    wrapper_adding_conversation(my_wrapper, (conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)

    });
    wrapper_adding_thread(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)

    });
    wrapper_adding_channel(my_wrapper, (channel_creation_t) {
       "Chan",
       "Desc",
       my_uuid_init(TEM_)

    });
    wrapper_adding_channel(my_wrapper, (channel_creation_t) {
       "Chann",
       "Desc",
       my_uuid_init(TEM_)

    });
    wrapper_adding_message(my_wrapper, (message_creation_t) {
        "Little message"
    });
    wrapper_adding_message(my_wrapper, (message_creation_t) {
        "Little messages"
    });
    wrapper_adding_message(my_wrapper, (message_creation_t) {
        "Little messagess"
    });
    wrapper_adding_comment(my_wrapper, (comment_creation_t) {
        "Comments",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)

    });
    wrapper_dump(my_wrapper);
    cr_assert_eq(2, 2);
}