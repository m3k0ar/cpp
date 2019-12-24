cmake_minimum_required(VERSION 3.13)
project(runner)

set(CMAKE_CXX_STANDARD 11)

# enable compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -Wpedantic -Weffc++")

# enable testing
include(CTest)

find_package(Catch2 REQUIRED)

add_subdirectory(src)
add_subdirectory(test)

# add_executable(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
# target_link_libraries(${PROJECT_NAME} logger)