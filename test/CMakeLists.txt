cmake_minimum_required(VERSION 2.6)

# Add the test executable
include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(GenericModuleTest
    GenericModuleTest.cc
    ${PROJECT_SOURCE_DIR}/src/GenericModule.cc)
target_link_libraries(GenericModuleTest -lboost_unit_test_framework)
