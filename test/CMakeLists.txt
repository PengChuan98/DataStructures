cmake_minimum_required(VERSION 3.20.0)
project(test LANGUAGES C)

# print current working directory
message("loading ${CMAKE_CURRENT_LIST_FILE}")

# append include and source files
include_directories(${INCLUDE_DIR_LIST})

add_executable(test_list test_list.c ${SRC_FILE_LIST})