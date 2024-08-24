cmake_minimum_required(VERSION 3.20)

project(BubbleBubble LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

# Sanitizer and Profiler Options
# Uncomment or conditionally set these based on the build type
#if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g")
#endif()
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")  # For profiling

# Apple Silicon Setup
if (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
endif ()

# Directories
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CLIENT_HEADERS_DIR ${BASE_DIR}/game_client/include)
set(CLIENT_SOURCES_DIR ${BASE_DIR}/game_client/src)
set(CLIENT_ASSETS_PATH ${BASE_DIR}/game_client/assets/)

file(GLOB_RECURSE SOURCE_FILES ${CLIENT_SOURCES_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CLIENT_HEADERS_DIR}/*.h)

# Module Path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

# Executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# Include Directories
target_include_directories(${PROJECT_NAME} PUBLIC ${BASE_DIR} ${CLIENT_HEADERS_DIR})

# Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE game_engine)

# Compile Definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE _DEFAULT_SOURCE=1)

# Subdirectories
add_subdirectory(${BASE_DIR}/game_core)
# Uncomment the following lines when you have separate CMakeLists for the client and server
# add_subdirectory(${BASE_DIR}/game_client)
# add_subdirectory(${BASE_DIR}/game_server)

# Compile Features and Warnings
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
enable_target_cxx_warnings(${PROJECT_NAME})