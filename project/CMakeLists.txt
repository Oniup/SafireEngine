cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME Sandbox)
set(PROJECT_VERSION VERSION 0.0.1)

file(GLOB_RECURSE PROJECT___SOURCE RECURSIVE ${CMAKE_CURRENT_SOURCE_DIR} "code/src/*.cpp")

add_executable(
    ${PROJECT_NAME} code/main.cpp 

    # projects source code
    ${PROJECT___SOURCE}
)

target_include_directories(
    ${PROJECT_NAME}

    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/safire_engine/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/safire_engine/thirdparty/
    PUBLIC ${CMAKE_SOURCE_DIR}/safire_engine/thirdparty/glfw/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/safire_engine/thirdparty/glad/
)

target_link_libraries(
    ${PROJECT_NAME}

    PUBLIC sfr_eng
)
