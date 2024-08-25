cmake_minimum_required(VERSION 3.20)

project(game_client LANGUAGES CXX)

# Print the target platform for debugging
message(STATUS "Target platform is ${TARGET_PLATFORM}")

# Set directories for the build
set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(_GAME_ASSETS_DIR ${_BASE_DIR}/assets)
set(_HEADERS_DIR ${_BASE_DIR}/include)
set(_SOURCES_DIR ${_BASE_DIR}/src)

# Grab all files as a glob
file (GLOB_RECURSE SOURCE_FILES ${_SOURCES_DIR}/*.cpp)
file (GLOB_RECURSE HEADER_FILES ${_HEADERS_DIR}/*.h)
file (GLOB_RECURSE ASSET_FILES  ${_GAME_ASSETS_DIR})

# OS based executable
if (TARGET_PLATFORM STREQUAL "MACOSX_BUNDLE")
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCE_FILES} ${ASSET_FILES})
elseif (TARGET_PLATFORM STREQUAL "WIN32")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${ASSET_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${ASSET_FILES})
endif ()

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${_HEADERS_DIR}
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        game_core
)

#Additional project settings (cmake helpers dir)
#$enable_target_cxx_warnings(${PROJECT_NAME})
set_target_cxx_standard(${PROJECT_NAME} 20)