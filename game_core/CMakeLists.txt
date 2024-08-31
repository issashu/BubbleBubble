cmake_minimum_required(VERSION 3.20)

project(game_core LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(_HEADERS_DIR ${_BASE_DIR}/include)
set(_SOURCES_DIR ${_BASE_DIR}/src)

file (GLOB_RECURSE SOURCE_FILES ${_SOURCES_DIR}/*.cpp)
file (GLOB_RECURSE HEADER_FILES ${_HEADERS_DIR}/*.h)

add_subdirectory(${_BASE_DIR}/externals/Asio)
add_subdirectory(${_BASE_DIR}/externals/Flecs)
add_subdirectory(${_BASE_DIR}/externals/SDL2)
add_subdirectory(${_BASE_DIR}/externals/SDL_image)
add_subdirectory(${_BASE_DIR}/externals/box2d)
add_subdirectory(${_BASE_DIR}/externals/flatbuffers)
add_subdirectory(${_BASE_DIR}/externals/tileson)
add_subdirectory(${_BASE_DIR}/externals/enkiTS)
add_subdirectory(${_BASE_DIR}/externals/enTT)
add_subdirectory(${_BASE_DIR}/externals/json_lib)

add_library(${PROJECT_NAME} STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${_HEADERS_DIR}
        PRIVATE
        ${_SOURCES_DIR}
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        AsioLib
        box2d
        enkiTS
        EnTT
        FlatBuffers
        FlecsLib
        nlohmann_json
        SDL2
        SDL2_image
        TilesonLib
        )

#Additional project settings (cmake helpers dir)
#enable_target_cxx_warnings(${PROJECT_NAME})