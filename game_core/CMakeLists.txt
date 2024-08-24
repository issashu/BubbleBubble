cmake_minimum_required(VERSION 3.20)

project(game_engine LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(_HEADERS_DIR ${_BASE_DIR}/include)
set(_SOURCES_DIR ${_BASE_DIR}/src)

file (GLOB_RECURSE SOURCE_FILES ${_SOURCES_DIR}/*.cpp)
file (GLOB_RECURSE HEADER_FILES ${_HEADERS_DIR}/*.h)

add_subdirectory(${_BASE_DIR}/Externals/Asio)
add_subdirectory(${_BASE_DIR}/Externals/Flecs)
add_subdirectory(${_BASE_DIR}/Externals/SDL2)
add_subdirectory(${_BASE_DIR}/Externals/box2d)
add_subdirectory(${_BASE_DIR}/Externals/flatbuffers)
add_subdirectory(${_BASE_DIR}/Externals/tileson)
add_subdirectory(${_BASE_DIR}/Externals/enkiTS)
add_subdirectory(${_BASE_DIR}/Externals/enTT)

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
        FlatBuffers
        FlecsLib
        SDL2
        TilesonLib
        enkiTS
        EnTT
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)