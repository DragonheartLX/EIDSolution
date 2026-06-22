# CMSIS Library

cmake_minimum_required(VERSION 3.25)

add_library(CMSIS_STM32F1xx INTERFACE)

target_include_directories(CMSIS_STM32F1xx INTERFACE 
"${CMAKE_CURRENT_LIST_DIR}/Include"
"${CMAKE_CURRENT_LIST_DIR}/Device/ST/STM32F1xx/Include"
)

add_library(CMSIS_STM32F4xx INTERFACE)

target_include_directories(CMSIS_STM32F4xx INTERFACE 
    "${CMAKE_CURRENT_LIST_DIR}/Include"
    "${CMAKE_CURRENT_LIST_DIR}/Device/ST/STM32F4xx/Include"
)

