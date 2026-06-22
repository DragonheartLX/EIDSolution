cmake_minimum_required(VERSION 3.25)

set(PROJ_TARGET_NAME    "Template")
set(PROJ_TARGET_BSP     "ZDYZ_F103Nano")

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(${PROJ_TARGET_NAME} C CXX ASM)

add_executable(${PROJ_TARGET_NAME})

# Link directories setup
target_link_directories(${PROJ_TARGET_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${PROJ_TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Application/main.c
)

# Add include paths
target_include_directories(${PROJ_TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

# Add project symbols (macros)
target_compile_definitions(${PROJ_TARGET_NAME} PRIVATE

)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${PROJ_TARGET_NAME} PRIVATE
    ${PROJ_TARGET_BSP}
)

# Execute post-build to print size, generate hex and bin
build_hex_bin(${PROJ_TARGET_NAME})
