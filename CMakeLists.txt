cmake_minimum_required(VERSION 3.20)
project(lab_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_5b main.c libs/data_structures/matrix/array.c libs/data_structures/matrix/array.h)

add_subdirectory(libs)
target_link_libraries(lab_5b matrix)
target_link_libraries(lab_5b array)

