set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/net_utils)
set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/server/net_utils/include)

set(TARGET_NAME net_utils)

add_subdirectory(fd_sets_manage)

set (SRC
     ${SRC_ROOT}/display_utils.c
     ${SRC_ROOT}/tcp_server.c
     ${SRC_ROOT}/remove_unused_sockets.c
     ${SRC_ROOT}/peer.c
     ${SRC_ROOT}/select.c
     ${INCLUDE_ROOT}/net_utils.h
     ${INCLUDE_ROOT}/net_utils/auth/user.h
     ${SRC_FD_SET_MANAGE}
)

add_library(${TARGET_NAME} ${SRC})

target_link_libraries(${TARGET_NAME} ${TARGET_NAME}_auth)

target_include_directories(${TARGET_NAME}
     PUBLIC ${INCLUDE_ROOT}
     PRIVATE ${SRC_ROOT}
     PRIVATE ${SRC_ROOT}/fd_sets_manage
)

add_subdirectory(auth)
