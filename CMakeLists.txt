cmake_minimum_required(VERSION 3.17)
project(myteams LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

enable_testing()

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_compile_options (
    "-std=gnu11" "-Werror" "-Wall" "-Wextra" "-Wpedantic" "-Wshadow" "-Wpointer-arith" "-Wattributes"
)

option(CODE_COVERAGE "Enable code coverage" OFF)
if (CODE_COVERAGE)
    add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
endif()

add_subdirectory(objects)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(tests)

add_custom_target (re
    COMMAND make clean && make
)

add_custom_target (fclean
    COMMAND make clean
    COMMAND rm -f ${PROJECT_NAME}_cli ${PROJECT_NAME}_server ${PROJECT_NAME}_objects
)

add_custom_target(tests_run
    COMMAND cmake ../ -B tests_build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON
    COMMAND cmake --build tests_build
    COMMAND ctest --test_dir build --output-on-failure -T test -T coverage
)

include(Dart)