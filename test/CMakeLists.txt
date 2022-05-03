cmake_minimum_required(VERSION 3.20.0)
project(test LANGUAGES C)

# print current working directory
message("loading ${CMAKE_CURRENT_LIST_FILE}")

# append include and source files
include_directories(${INCLUDE_DIR_LIST})

# auto add executables
macro(AUTO_ADD_EXECUTABLE)
    file(GLOB_RECURSE children "${PROJECT_SOURCE_DIR}/test*.c")
    foreach(child ${children})
        string(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILENAME ${child})
        add_executable(${FILENAME} ${FILENAME}.c ${SRC_FILE_LIST})
    endforeach()
endmacro()

AUTO_ADD_EXECUTABLE()