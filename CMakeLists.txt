cmake_minimum_required(VERSION 3.2)


if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()
project(RGBA_build) 


set(CMAKE_CXX_STANDARD 17)

add_executable(RGBA)
target_include_directories(RGBA PRIVATE include)
target_sources(RGBA PRIVATE src/main.cpp)

###Testing Code#
find_package(GTest CONFIG REQUIRED)
include_directories(include)
include(GoogleTest)
enable_testing()
add_executable(RGBATests)
target_include_directories(RGBATests PRIVATE include)
target_sources(RGBATests PRIVATE tests/RGBATests.cpp)
target_link_libraries(RGBATests PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(RGBATests)

