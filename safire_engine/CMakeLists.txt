cmake_minimum_required(VERSION 3.20)

set(SAFIRE_ENGINE sfr_eng)
project(${SAFIRE_ENGINE} VERSION 0.0.1)

find_package(OpenGL REQUIRED)

# setting up glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

if (UNIXi OR APPLE)
    find_package(glfw3)
    if (!${glfw3_FOUND})
        add_subdirectory(thirdparty/glfw)
    endif ()
elseif (WIN32)
    add_subdirectory(thirdparty/glfw)
    # TODO: add assimp and freetype here
endif ()

add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/imgui)

file(GLOB_RECURSE SAFIRE_ENGINE___CORE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/core/*.cpp")
file(GLOB_RECURSE SAFIRE_ENGINE___RENDERER_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/renderer/*.cpp")
file(GLOB_RECURSE SAFIRE_ENGINE___TOOLS_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/tools/*.cpp")

file(GLOB_RECURSE SAFIRE_ENGINE___CORE_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/safire/core/*.cpp")
file(GLOB_RECURSE SAFIRE_ENGINE___RENDERER_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/safire/renderer/*.cpp")
file(GLOB_RECURSE SAFIRE_ENGINE___TOOLS_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/safire/tools/*.cpp")

add_library(
    ${SAFIRE_ENGINE} STATIC 

    ${SAFIRE_ENGINE___CORE_SOURCES} 
    # ${SAFIRE_ENGINE___RENDERER_SOURCES}
    ${SAFIRE_ENGINE___TOOLS_SOURCES}

    ${SAFIRE_ENGINE___CORE_HEADERS}
    # ${SAFIRE_ENGINE___RENDERER_HEADERS}
    ${SAFIRE_ENGINE___TOOLS_HEADERS}
)

target_include_directories(
    ${SAFIRE_ENGINE}

    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
    ${SAFIRE_ENGINE}

    PUBLIC OpenGL::GL
    # PUBLIC glad
    PUBLIC glfw
    # PUBLIC imgui
)
