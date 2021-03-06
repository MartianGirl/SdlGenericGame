cmake_minimum_required(VERSION 2.6)
project(SdlGenericGame)

# Use FindSDL2 module
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
message("Adding ${PROJECT_SOURCE_DIR}/cmake to CMAKE_MODULE_PATH...")

# Set an output directory for our binaries
set(PROJECT_INSTALL_DIR ${PROJECT_SOURCE_DIR}/bin)
message("Setting PROJECT_INSTALL_DIR to ${PROJECT_SOURCE_DIR}/bin")

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users
# choose this when selecting the build mode in their IDE.
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR
        ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_RELEASE
        "${CMAKE_CXX_FLAGS} -O2")
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]"
            "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Look in the src subdirectory
add_subdirectory(src)

# Look in the test subdirectory
add_subdirectory(test)
