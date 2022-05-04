set (INCLUDE_DIR ${PROJECT_SOURCE_DIR}/client/src/include)
set (SRC_DIR ${PROJECT_SOURCE_DIR}/client/src)

set (TARGET ${PROJECT_NAME}_cli)

set (SRC
    ${SRC_DIR}/entrypoint.c
)

add_executable(${TARGET} ${SRC})
