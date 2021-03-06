/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_channel_tests
*/

#include <criterion/criterion.h>
#include "object_channel.h"

Test(objects_my_channel, classic) {
    channel_t *my_channel = channel_init((channel_creation_t) {
        "My_Channel",
        "I'm a glorious channel",
        my_uuid_init(TEM_)
    });

    cr_assert_not_null(my_channel);
}

Test(objects_my_channel, dump) {
    channel_t *my_channel = channel_init((channel_creation_t) {
        "My_Channel",
        "I'm a glorious channel",
        my_uuid_init(TEM_)
    });

    channel_dump(my_channel); /// TO REFACTO WITH USERJOURNEY
}

Test(objects_my_channel, invalid_name) {
    channel_t *my_channel = channel_init((channel_creation_t) {
        "My_Channelllllllllllllllllllllllllllllllllllllll",
        "I'm a glorious channel",
        my_uuid_init(TEM_)
    });

    cr_assert_null(my_channel);
}

Test(objects_my_channel, invalid_desc) {
    channel_t *my_channel = channel_init((channel_creation_t) {
        "You lose the game",
        "I'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channelI'm a glorious channel",
        my_uuid_init(TEM_)
    });

    cr_assert_null(my_channel);
}

Test(objects_my_channel, setter) {
    channel_t *channel = channel_init((channel_creation_t) {
        "My_Channel",
        "I'm a glorious channel",
        my_uuid_init(TEM_)
    });

    channel_edit_uuid(channel, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    channel_edit_name(channel, "A");
    channel_edit_parent(channel, "TEM_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    channel_add_threads(channel, my_uuid_init(THR_));

    cr_assert_eq(channel->threads_n, 1);
    cr_assert_str_eq(channel->uuid->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(channel->name, "A");
    cr_assert_str_eq(channel->team->uuid.repr, "TEM_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
}

Test(objects_my_channel, destroy_classic) {
    channel_t *my_channel = channel_init((channel_creation_t) {
        "My_Channel",
        "I'm a glorious channel",
        my_uuid_init(TEM_)
    });

    channel_destroy(my_channel);
}