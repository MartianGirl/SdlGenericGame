cmake_minimum_required(VERSION 2.6)
project(SdlGenericGameExecutable)
# Version number
set(SdlGenericGameExecutable_VERSION_MAJOR 0)
set(SdlGenericGameExecutable_VERSION_MINOR 1)

# Configure a header file to pass some of the CMake settings
# to the source code.
configure_file(
    "${PROJECT_SOURCE_DIR}/Config.h.in"
    "${PROJECT_SOURCE_DIR}/Config.h"
    )
message("Using ${PROJECT_SOURCE_DIR}/Config.h.in to create "
    "${PROJECT_SOURCE_DIR}/Config.h")

# Add the executable
add_executable(SdlGenericGameExecutable SdlGenericGame.cc)
target_link_libraries(SdlGenericGameExecutable ${SDL2_LIBRARY})
install(
    TARGETS SdlGenericGameExecutable
    RUNTIME
    DESTINATION ${PROJECT_INSTALL_DIR})
