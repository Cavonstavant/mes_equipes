set(INC_PARSER ${PROJECT_SOURCE_DIR}/server/src/parser/include)
set(SRC_PARSER ${PROJECT_SOURCE_DIR}/server/src/parser)

set(SRC
    ${SRC_PARSER}/cli_commands.c
    ${SRC_PARSER}/compute_command.c
    ${SRC_PARSER}/call_command.c
    ${SRC_PARSER}/convert_command_to_structure.c
    ${SRC_PARSER}/fill_command_arguments.c
    ${SRC_PARSER}/print_retcode.c
    ${SRC_PARSER}/cli_commands.h
    ${INC_PARSER}/parser.h
)

set(TARGET ${PROJECT_NAME}_parser)

add_library(${TARGET} ${SRC})

target_link_libraries(${TARGET}
    PUBLIC ${PROJECT_NAME}_commands
)

target_include_directories(${TARGET}
    PUBLIC ${INC_PARSER}
    PRIVATE ${SRC_PARSER}
)
