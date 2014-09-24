cmake_minimum_required(VERSION 2.6)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
# Add the test executable
include_directories(${PROJECT_SOURCE_DIR}/src ${Boost_INCLUDE_DIR})
add_executable(GenericModuleTest
    GenericModuleTest.cc
    ${PROJECT_SOURCE_DIR}/src/GenericModule.cc)
target_link_libraries(GenericModuleTest ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
