set (INCLUDE_BODY ${PROJECT_SOURCE_DIR}/objects/body/include)
set (INCLUDE_CHANNEL ${PROJECT_SOURCE_DIR}/objects/channel/include)
set (INCLUDE_COMMENT ${PROJECT_SOURCE_DIR}/objects/comment/include)
set (INCLUDE_CONVERSATION ${PROJECT_SOURCE_DIR}/objects/conversation/include)
set (INCLUDE_DESCRIPTION ${PROJECT_SOURCE_DIR}/objects/description/include)
set (INCLUDE_MESSAGE ${PROJECT_SOURCE_DIR}/objects/message/include)
set (INCLUDE_NAME ${PROJECT_SOURCE_DIR}/objects/name/include)
set (INCLUDE_STATUS ${PROJECT_SOURCE_DIR}/objects/status/include)
set (INCLUDE_TEAM ${PROJECT_SOURCE_DIR}/objects/team/include)
set (INCLUDE_THREAD ${PROJECT_SOURCE_DIR}/objects/thread/include)
set (INCLUDE_USER ${PROJECT_SOURCE_DIR}/objects/user/include)
set (INCLUDE_UUID ${PROJECT_SOURCE_DIR}/objects/uuid/include)
set (INCLUDE_UUID_WRAPPER
    ${PROJECT_SOURCE_DIR}/objects/uuid/uuid_wrapper/src/include
)

set (INCLUDE_WRAPPER ${PROJECT_SOURCE_DIR}/objects/wrapper/include)

set (SRC_BODY ${PROJECT_SOURCE_DIR}/objects/body/src)
set (SRC_CHANNEL ${PROJECT_SOURCE_DIR}/objects/channel/src)
set (SRC_COMMENT ${PROJECT_SOURCE_DIR}/objects/comment/src)
set (SRC_CONVERSATION ${PROJECT_SOURCE_DIR}/objects/conversation/src)
set (SRC_DESCRIPTION ${PROJECT_SOURCE_DIR}/objects/description/src)
set (SRC_MESSAGE ${PROJECT_SOURCE_DIR}/objects/message/src)
set (SRC_NAME ${PROJECT_SOURCE_DIR}/objects/name/src)
set (SRC_STATUS ${PROJECT_SOURCE_DIR}/objects/status/src)
set (SRC_TEAM ${PROJECT_SOURCE_DIR}/objects/team/src)
set (SRC_THREAD ${PROJECT_SOURCE_DIR}/objects/thread/src)
set (SRC_USER ${PROJECT_SOURCE_DIR}/objects/user/src)
set (SRC_UUID ${PROJECT_SOURCE_DIR}/objects/uuid/src)

set (SRC_WRAPPER ${PROJECT_SOURCE_DIR}/objects/wrapper/src)

set (TARGET ${PROJECT_NAME}_objects)

set (SRC
    ${SRC_BODY}/object_body.c
    ${SRC_BODY}/body_dump.c
    ${SRC_BODY}/body_setter.c
    ${SRC_CHANNEL}/object_channel.c
    ${SRC_CHANNEL}/channel_dump.c
    ${SRC_CHANNEL}/channel_setter.c
    ${SRC_COMMENT}/object_comment.c
    ${SRC_COMMENT}/comment_dump.c
    ${SRC_COMMENT}/comment_setter.c
    ${SRC_CONVERSATION}/object_conversation.c
    ${SRC_CONVERSATION}/conversation_dump.c
    ${SRC_CONVERSATION}/conversation_setter.c
    ${SRC_DESCRIPTION}/object_description.c
    ${SRC_DESCRIPTION}/description_dump.c
    ${SRC_DESCRIPTION}/description_setter.c
    ${SRC_MESSAGE}/object_message.c
    ${SRC_MESSAGE}/message_dump.c
    ${SRC_MESSAGE}/message_setter.c
    ${SRC_NAME}/object_name.c
    ${SRC_NAME}/name_dump.c
    ${SRC_NAME}/name_setter.c
    ${SRC_STATUS}/object_status.c
    ${SRC_STATUS}/status_dump.c
    ${SRC_STATUS}/status_setter.c
    ${SRC_TEAM}/object_team.c
    ${SRC_TEAM}/team_dump.c
    ${SRC_TEAM}/team_setter.c
    ${SRC_TEAM}/team_remove.c
    ${SRC_THREAD}/object_thread.c
    ${SRC_THREAD}/thread_dump.c
    ${SRC_THREAD}/thread_setter.c
    ${SRC_USER}/object_user.c
    ${SRC_USER}/user_dump.c
    ${SRC_USER}/user_setter.c
    ${SRC_USER}/user_remove.c
    ${SRC_UUID}/object_uuid.c
    ${SRC_UUID}/uuid_dump.c
    ${SRC_UUID}/uuid_setter.c
    ${SRC_UUID}/uuid_cmp.c
    ${SRC_WRAPPER}/object_wrapper.c
    ${SRC_WRAPPER}/upper_component_adding.c
    ${SRC_WRAPPER}/lower_component_adding.c
    ${SRC_WRAPPER}/component_dump.c
    ${SRC_WRAPPER}/upper_component_get.c
    ${SRC_WRAPPER}/lower_component_get.c
    ${SRC_WRAPPER}/wrapper_interaction.c
    ${SRC_WRAPPER}/wrapper_modification.c
    ${SRC_WRAPPER}/find_by_name.c
    ${SRC_WRAPPER}/get_child_list.c
    ${SRC_WRAPPER}/user_and_team_relation.c
    ${SRC_WRAPPER}/get_associated_team.c
    ${SRC_WRAPPER}/pack_wrapper_to_json.c
)

add_library(${TARGET} ${SRC})

target_link_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

target_link_libraries(${TARGET}
    PRIVATE ${PROJECT_NAME}_uuid_wrapper
    PUBLIC myteams
)

target_include_directories(${TARGET}
    PUBLIC ${INCLUDE_BODY}
    PUBLIC ${INCLUDE_CHANNEL}
    PUBLIC ${INCLUDE_COMMENT}
    PUBLIC ${INCLUDE_CONVERSATION}
    PUBLIC ${INCLUDE_DESCRIPTION}
    PUBLIC ${INCLUDE_MESSAGE}
    PUBLIC ${INCLUDE_NAME}
    PUBLIC ${INCLUDE_STATUS}
    PUBLIC ${INCLUDE_TEAM}
    PUBLIC ${INCLUDE_THREAD}
    PUBLIC ${INCLUDE_USER}
    PUBLIC ${INCLUDE_UUID}
    PUBLIC ${INCLUDE_WRAPPER}
    PUBLIC ${INCLUDE_UUID_WRAPPER}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
    PRIVATE ${SRC_ROOT}
)

add_subdirectory(uuid/uuid_wrapper)

set_property(
     TARGET ${TARGET} PROPERTY POSITION_INDEPENDENT_CODE ON
)


# add_executable(a.out ${PROJECT_SOURCE_DIR}/objects/main.c)

# target_link_libraries(a.out
#     PUBLIC ${TARGET}
# )