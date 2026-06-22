cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(EmIDF C CXX ASM)

message(STATUS "=================== EmIDF Building ===================")
message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Project: " ${PROJ_TARGET})
message(STATUS "Chip: " ${PROJ_CHIP_NAME})
message(STATUS "======================================================")

set(EIDS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")

configure_file(
    ${EIDS_ROOT}/cmake/clangd.in
    ${EIDS_ROOT}/.clangd
    @ONLY
)

include(${EIDS_ROOT}/cmake/Utils.cmake)
include(${EIDS_ROOT}/cmake/Chip/${PROJ_CHIP_NAME}.cmake)

# Library
add_subdirectory(Library)
# EIDSolution
# add_subdirectory(EIDSolution)
# BSP
add_subdirectory(Board)
# Projects
add_subdirectory(Project)