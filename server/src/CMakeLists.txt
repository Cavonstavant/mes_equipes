set (INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/server/src/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/src)

set (TARGET ${PROJECT_NAME}_server)

set (SRC
    ${SRC_ROOT}/entrypoint.c
    ${SRC_ROOT}/cli_commands.c
    ${SRC_ROOT}/compute_command.c
    ${SRC_ROOT}/call_command.c
    ${SRC_ROOT}/convert_command_to_structure.c
    ${SRC_ROOT}/fill_command_arguments.c
    ${INCLUDE_DIRS}/cli_commands.h
    ${INCLUDE_DIRS}/rcodes.h
    ${INCLUDE_DIRS}/parser.h
)

add_executable(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
    PRIVATE ${INCLUDE_DIRS}
    PRIVATE ${SRC_ROOT}
)

target_link_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${TARGET}
    PUBLIC myteams
)
