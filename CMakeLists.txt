cmake_minimum_required(VERSION 3.20)

project(BubbleBubble LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

#Remove/Comment before final build or before using Valgrind (CLion specific sanitizer options)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-address-use-after-scope  -fno-omit-frame-pointer -g")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g")
#Uncomment below line in order to run the Clion profiler:
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

#Uncomment below for Apple Silicon setups
#set(CMAKE_OSX_ARCHITECTURES "arm64")

#Set directories below
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CLIENT_HEADERS_DIR ${BASE_DIR}/game_client/include)
set(CLIENT_SOURCES_DIR ${BASE_DIR}/game_client/src)
set(CLIENT_ASSETS_PATH ${BASE_DIR}/game_client/assets/)

# This appends a complex path to a variable. Set it as itself and then set the path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

add_executable( ${PROJECT_NAME}
        ${CLIENT_HEADERS_DIR}/main.h
        ${CLIENT_SOURCES_DIR}/main.cpp
        )

target_include_directories (
        ${PROJECT_NAME}
        PUBLIC
        ${BASE_DIR}
        )

target_link_libraries (
        ${PROJECT_NAME}
        PRIVATE
        game_engine
        )

target_compile_definitions (
        ${PROJECT_NAME}
        PRIVATE
        _DEFAULT_SOURCE=1
        )

add_subdirectory(${BASE_DIR}/game_engine)
#Add a general CMakeLists for the project and separate for game client and server
#add_subdirectory(${BASE_DIR}/game_client)
#add_subdirectory(${BASE_DIR}/game_server)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
enable_target_cxx_warnings(${PROJECT_NAME})