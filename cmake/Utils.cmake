# Execute post-build to print size, generate hex and bin

function(build_hex_bin TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${TARGET_NAME}>
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${TARGET_NAME}> $<CONFIG>/${TARGET_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TARGET_NAME}> $<CONFIG>/${TARGET_NAME}.bin
    )
endfunction()