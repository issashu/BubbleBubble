cmake_minimum_required(VERSION 3.20)

project(BubbleBubble LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

# Sanitizer and Profiler Options
# Uncomment or conditionally set these based on the build type

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")  # For profiling

#if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g")
#endif()

#if(CMAKE_BUILD_TYPE STREQUAL "Release")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")  # Optimize for Release
#endif()

# Apple Silicon Setup
if (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
endif ()

# Determine the OS platform and set a variable accordingly
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(TARGET_PLATFORM "MACOSX_BUNDLE")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(TARGET_PLATFORM "WIN32")
else ()
    set(TARGET_PLATFORM "")
endif ()

# Module Path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

# Subdirectories
add_subdirectory(game_core)
add_subdirectory(game_client)
#add_subdirectory(game_server)

# Global Settings
# Global Settings
add_compile_definitions(_DEFAULT_SOURCE=1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)