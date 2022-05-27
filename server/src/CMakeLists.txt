set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/server/src/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/src)

set (CORE_TARGET ${PROJECT_NAME}_server_core)

add_library(${CORE_TARGET} SHARED
    ${SRC_ROOT}/my_teams_server.c
    ${INCLUDE_ROOT}/my_teams_server.h
    ${INCLUDE_ROOT}/client_wrapper.h
    ${SRC_ROOT}/client_wrapper.c
)

target_include_directories(${CORE_TARGET}
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)

target_link_libraries(${CORE_TARGET}
    PUBLIC net_utils
    # PUBLIC ${PROJECT_NAME}_commands
)

set (TARGET ${PROJECT_NAME}_server)

set (SRC
    ${SRC_ROOT}/entrypoint.c
)

add_executable(${TARGET} ${SRC})

target_link_libraries(${TARGET}
    PUBLIC ${CORE_TARGET}
)

# target_include_directories(${TARGET}_core
#     PUBLIC ${INCLUDE_ROOT}
#     PRIVATE ${SRC_ROOT}
#     PRIVATE ${TARGET_NAME}_commands
# )

# target_link_directories(${TARGET}_core
#     PRIVATE ${PROJECT_SOURCE_DIR}/server/net_utils
# )

target_include_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

target_link_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${TARGET}
    PRIVATE ${PROJECT_NAME}_commands
    PUBLIC myteams
)

add_subdirectory(commands)