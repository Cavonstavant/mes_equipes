set (INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/server/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/src)

set (TARGET ${PROJECT_NAME}_server)

set (SRC_CORE
    ${SRC_ROOT}/server_run.c
    ${SRC_ROOT}/server_data.c
    ${SRC_ROOT}/my_teams_server.c
)

set (SRC
    ${SRC_ROOT}/entrypoint.c
)

add_executable(${TARGET} ${SRC})

add_library(${TARGET}_core ${SRC_CORE})

# target_include_directories(${TARGET}_core
#     PUBLIC ${INCLUDE_DIRS}
#     PRIVATE ${SRC_ROOT}
#     PRIVATE ${TARGET_NAME}_commands
# )

# target_link_directories(${TARGET}_core
#     PRIVATE ${PROJECT_SOURCE_DIR}/server/net_utils
# )

target_include_directories(${TARGET}_core
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
    PUBLIC ${INCLUDE_DIRS}
    PRIVATE ${PROJECT_SOURCE_DIR}/objects
    PRIVATE ${SRC_ROOT}
)

target_link_directories(${TARGET}_core
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${TARGET}_core
    PRIVATE ${PROJECT_NAME}_commands
    PRIVATE ${PROJECT_NAME}_objects
    PRIVATE net_utils
    PUBLIC myteams
)

target_link_libraries(${TARGET}
    PRIVATE ${TARGET}_core
)

add_subdirectory(commands)