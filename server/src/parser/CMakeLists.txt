set(INC_PARSER ${PROJECT_SOURCE_DIR}/server/src/parser/include)
set(SRC_PARSER ${PROJECT_SOURCE_DIR}/server/src/parser)

set(SRC
    ${SRC_PARSER}/call_command.c
    ${SRC_PARSER}/check_command.c
    ${SRC_PARSER}/cli_commands.c
    ${SRC_PARSER}/cli_commands.h
    ${SRC_PARSER}/my_str_to_word_array.c
    ${SRC_PARSER}/split_command.c
    ${SRC_PARSER}/compute_command.c
)

set(TARGET ${PROJECT_NAME}_parser)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INC_PARSER}
    PRIVATE ${SRC_PARSER}
)