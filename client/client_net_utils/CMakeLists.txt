set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/client/client_net_utils/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/client/client_net_utils)

set (SRC
    ${SRC_ROOT}/client_utils.c
    ${INCLUDE_ROOT}/client_utils.h
)

add_library(${PROJECT_NAME}_client_net_utils SHARED
    ${SRC}
)

target_include_directories(${PROJECT_NAME}_client_net_utils
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)
