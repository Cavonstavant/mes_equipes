set(INC_ROOT ${PROJECT_SOURCE_DIR}/server/src/core/include)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/server/src/core)

set(TARGET ${PROJECT_NAME}_server_core)

set(SRC
    ${SRC_ROOT}/call_command.c
    ${SRC_ROOT}/cli_commands.c
    ${SRC_ROOT}/compute_command.c
    ${SRC_ROOT}/convert_command_to_structure.c
    ${SRC_ROOT}/fill_command_arguments.c
    ${SRC_ROOT}/my_teams_server.c
    ${SRC_ROOT}/server_data.c
    ${SRC_ROOT}/server_run.c
    ${SRC_ROOT}/auth_command.c
    ${SRC_ROOT}/subscribe_command.c
    ${SRC_ROOT}/create_command.c
    ${SRC_ROOT}/use_command.c

    ${INC_ROOT}/cli_commands.h
    ${INC_ROOT}/entrypoint.h
    ${INC_ROOT}/my_teams_server.h
    ${INC_ROOT}/parser.h
    ${INC_ROOT}/rcodes.h
    ${INC_ROOT}/server.h
)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INC_ROOT}
    PRIVATE ${SRC_ROOT}
)

target_link_libraries(${TARGET}
    PRIVATE ${PROJECT_NAME}_objects
    PRIVATE net_utils
    PUBLIC myteams_api
)
