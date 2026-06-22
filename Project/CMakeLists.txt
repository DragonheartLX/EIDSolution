# Add specific project

if (DEFINED PROJ_TARGET)
        if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_TARGET})
            message(FATAL_ERROR "PROJ_TARGET ${PROJ_TARGET} not found")
        endif()
        add_subdirectory(${PROJ_TARGET})
else()
    message(FATAL_ERROR "PROJ_TARGET not defined")
endif()
