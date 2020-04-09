cmake_minimum_required(VERSION 2.8)
project(webserver)

add_subdirectory(${CMAKE_SOURCE_DIR}/pkg)
add_subdirectory(${CMAKE_SOURCE_DIR}/cmd)
add_subdirectory(${CMAKE_SOURCE_DIR}/internal)

add_executable(webserver main.c)
target_link_libraries(webserver pkg cmd)

add_executable(webclient cmd/client.c)

