set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/server/net_utils/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/net_utils/auth)

set (TARGET_NAME net_utils_auth)

set (SRC
    ${SRC_ROOT}/user.c
)

add_library(${TARGET_NAME} ${SRC})

target_include_directories(${TARGET_NAME}
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)

