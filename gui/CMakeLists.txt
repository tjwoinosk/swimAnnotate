set(BINARY ${CMAKE_PROJECT_NAME}_gui)

file(GLOB_RECURSE GUI_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${GUI_SOURCES})

add_executable(${BINARY} WIN32 ${GUI_SOURCES})

add_custom_command(TARGET ${BINARY} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/rc
        ${CMAKE_CURRENT_BINARY_DIR}/Debug/rc)
		
add_custom_command(TARGET ${BINARY} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/rc
        ${CMAKE_CURRENT_BINARY_DIR}/Release/rc)

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(${BINARY} PRIVATE third::wx)

