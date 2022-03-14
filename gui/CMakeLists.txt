set(BINARY ${CMAKE_PROJECT_NAME}_gui)

file(GLOB_RECURSE GUI_SOURCES LIST_DIRECTORIES false *.h *.cpp *.rc)
set(SOURCES ${GUI_SOURCES})

add_executable(${BINARY} WIN32 ${GUI_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(${BINARY} PRIVATE third::wx)