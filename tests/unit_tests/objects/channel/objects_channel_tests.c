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

Test(objects_my_channel, destroy_classic) {
    channel_t *my_channel = channel_init((channel_creation_t) {
        "My_Channel",
        "I'm a glorious channel",
        my_uuid_init(TEM_)
    });

    channel_destroy(my_channel);
}