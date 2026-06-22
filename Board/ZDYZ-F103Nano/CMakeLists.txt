# LCKFB-tkx-E BSP Library
cmake_minimum_required(VERSION 3.25)

add_library(ZDYZ_F103Nano INTERFACE)

target_compile_definitions(ZDYZ_F103Nano INTERFACE
    USE_HAL_DRIVER
    USE_HAL_LEGACY
    STM32F103xE
    $<$<CONFIG:Debug>:DEBUG>
)

target_sources(ZDYZ_F103Nano INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/Source/Core/stm32f1xx_hal_msp.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/Core/stm32f1xx_it.c
    ${CMAKE_CURRENT_LIST_DIR}/Source/Core/system_stm32f1xx.c
    ${EIDS_ROOT}/Library/Startup/startup_stm32f103xe.s

    ${CMAKE_CURRENT_LIST_DIR}/Source/Board/Board.c
)

target_include_directories(ZDYZ_F103Nano INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/Include
)

target_link_options(ZDYZ_F103Nano INTERFACE
    "-T${EIDS_ROOT}/Library/LinkerScript/STM32F103RC_FLASH.ld"
)

target_link_libraries(ZDYZ_F103Nano INTERFACE
    ${TOOLCHAIN_LINK_LIBRARIES}
    CMSIS_STM32F1xx
    STM32F1xx_HAL_Driver
)