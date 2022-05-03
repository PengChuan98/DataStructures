cmake_minimum_required(VERSION 3.20.0)
project(src LANGUAGES C)

# print current working directory
message(STATUS "START ${PROJECT_SOURCE_DIR}")

# collect all include files
macro(FIND_INCLUDE_DIR result curdir)
    file(GLOB_RECURSE children "${curdir}/*.hpp" "${curdir}/*.h" )
    set(dirlist "")
    foreach(child ${children})
        string(REGEX REPLACE "(.*)/.*" "\\1" LIB_NAME ${child})
        if(IS_DIRECTORY ${LIB_NAME})
            LIST(APPEND dirlist ${LIB_NAME})
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()
FIND_INCLUDE_DIR(INCLUDE_DIR_LIST ${PROJECT_SOURCE_DIR})
message(STATUS "INCLUDE_DIR_LIST = ${INCLUDE_DIR_LIST}")

# collect all source files
file(GLOB_RECURSE SRC_FILE_LIST "${PROJECT_SOURCE_DIR}/*.c" "${PROJECT_SOURCE_DIR}/*.cpp")
message(STATUS "SRC_FILE_LIST = ${SRC_FILE_LIST}")

# set global variables
set(INCLUDE_DIR_LIST ${INCLUDE_DIR_LIST} CACHE INTERNAL "INCLUDE_DIR_LIST")
set(SRC_FILE_LIST ${SRC_FILE_LIST} CACHE INTERNAL "SRC_FILE_LIST")

message(STATUS "FINISH ${PROJECT_SOURCE_DIR}")

# append current directory
include_directories(${INCLUDE_DIR_LIST})