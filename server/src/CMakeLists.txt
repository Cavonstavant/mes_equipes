set (INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/server/src/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/src)

set (TARGET ${PROJECT_NAME}_server)

set (SRC
    ${SRC_ROOT}/entrypoint.c
)

add_executable(${TARGET} ${SRC})

# target_include_directories(${TARGET}_core
#     PUBLIC ${INCLUDE_DIRS}
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
    PRIVATE ${PROJECT_NAME}_parser
    PRIVATE ${PROJECT_NAME}_commands
    PUBLIC myteams
)

add_subdirectory(parser)
add_subdirectory(commands)

# target_link_libraries(${TARGET}
#     PRIVATE ${PROJECT_NAME}_commands
# )
