cmake_minimum_required(VERSION 2.6)
project(SdlGenericGame)

# Version number
set(SdlGenericGame_VERSION_MAJOR 0)
set(SdlGenericGame_VERSION_MINOR 1)

# Configure a header file to pass some of the CMake settings
# to the source code.
configure_file(
    "${PROJECT_SOURCE_DIR}/Config.h.in"
    "${PROJECT_SOURCE_DIR}/Config.h"
    )

# Add the executable
add_executable(SdlGenericGame SdlGenericGame.cc)
target_link_libraries(SdlGenericGame ${SDL2_LIBRARY})
install(TARGETS SdlGenericGame RUNTIME DESTINATION ${BIN_DIR})
