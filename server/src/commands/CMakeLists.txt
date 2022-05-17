set (INC_COMMANDS ${PROJECT_SOURCE_DIR}/server/src/commands)
set (SRC_COMMANDS ${PROJECT_SOURCE_DIR}/server/src/commands)

set (SRC)

set (TARGET ${PROJECT_NAME}_commands)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INC_COMMANDS}
    PRIVATE ${SRC_COMMANDS}
)
