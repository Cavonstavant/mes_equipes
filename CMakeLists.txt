cmake_minimum_required(VERSION 3.17)
project(myteams LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

enable_testing()

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/myteams)

add_compile_options (
   "-Werror" "-Wall" "-Wextra" "-Wpedantic" "-Wshadow" "-Wpointer-arith" "-Wattributes"
)

option(CODE_COVERAGE "Enable code coverage" OFF)
if (CODE_COVERAGE)
    add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_subdirectory(tests)
endif()

add_custom_target (re
    COMMAND make clean && make
)

add_custom_target (fclean
    COMMAND make clean
    COMMAND rm -f ${PROJECT_NAME}_cli ${PROJECT_NAME}_server ${PROJECT_NAME}_objects
)

set (LIBS_PATH ${PROJECT_SOURCE_DIR}/libs)

add_library(myteams SHARED IMPORTED)

set_target_properties(myteams PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/libs/myteams
    IMPORTED_NO_SONAME ON
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/myteams/libmyteams.so
)

add_subdirectory(objects)
add_subdirectory(client)
add_subdirectory(server)