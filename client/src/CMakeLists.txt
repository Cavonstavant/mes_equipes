set (INCLUDE_DIR ${PROJECT_SOURCE_DIR}/client/src/include)
set (SRC_DIR ${PROJECT_SOURCE_DIR}/client/src)

set (TARGET ${PROJECT_NAME}_cli)
set (CORE_TARGET ${PROJECT_NAME}_cli_core)


set (CORE_SRC
    ${SRC_DIR}/teams_client.c
    ${SRC_DIR}/run_teams_client.c
    ${SRC_DIR}/stop_teams_client.c
    ${INCLUDE_DIR}/teams_client.h
    ${INCLUDE_DIR}/teams_responses.h
)

set (SRC
    ${SRC_DIR}/entrypoint.c
)

add_library(${CORE_TARGET} ${CORE_SRC})

target_link_libraries(${CORE_TARGET}
    PUBLIC ${PROJECT_NAME}_client_net_utils
    PUBLIC myteams_api
)

target_include_directories(${CORE_TARGET}
    PUBLIC ${INCLUDE_DIR}
    PRIVATE ${SRC_DIR}
)

add_executable(${TARGET} ${SRC})

target_link_libraries(${TARGET}
    PUBLIC ${CORE_TARGET}
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)