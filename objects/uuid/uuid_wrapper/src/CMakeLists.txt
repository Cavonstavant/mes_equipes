set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/objects/uuid/uuid_wrapper/src/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/objects/uuid/uuid_wrapper/src)

set (TARGET ${PROJECT_NAME}_uuid_wrapper)

set (SRC
    ${SRC_ROOT}/my_uuid.c
    ${SRC_ROOT}/uuid_prefixes.c
)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)
target_link_libraries(${TARGET}
    PRIVATE uuid
)
