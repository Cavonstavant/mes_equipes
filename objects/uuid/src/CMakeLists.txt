set (INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/objects/uuid/include)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/objects/uuid/src)

set (TARGET ${PROJECT_NAME}_objects)

set (SRC
    ${SRC_ROOT}/object_uuid.c
)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INCLUDE_DIRS}
    PRIVATE ${SRC_ROOT}
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)