set (INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/objects/includes)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/objects/src)

set (TARGET ${PROJECT_NAME}_objects)

set (SRC
    ${SRC_ROOT}/object_body.c
    ${SRC_ROOT}/object_channel.c
    ${SRC_ROOT}/object_comment.c
    ${SRC_ROOT}/object_conversation.c
    ${SRC_ROOT}/object_description.c
    ${SRC_ROOT}/object_message.c
    ${SRC_ROOT}/object_name.c
    ${SRC_ROOT}/object_status.c
    ${SRC_ROOT}/object_team.c
    ${SRC_ROOT}/object_thread.c
    ${SRC_ROOT}/object_user.c
    ${SRC_ROOT}/object_uuid.c
)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INCLUDE_DIRS}
    PRIVATE ${SRC_ROOT}
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)