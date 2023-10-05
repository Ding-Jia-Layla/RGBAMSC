###This file is used to specify how the C++ project should be built
###Makefiles is the compiler


###PROJECT CONFIGURATION
###minimum required cmake version
cmake_minimum_required(VERSION 3.2)
###project declaration
project(RGBA_build) 
###cmake toolchain(compilers,linkers...) especially for the cross-compilation
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()


###setting the c++ standard(COMPILATION STANDARDS)
set(CMAKE_CXX_STANDARD 17)

### building the main executable file(SOURCE FILES)
add_executable(RGBA)
target_include_directories(RGBA PRIVATE include)
target_sources(RGBA PRIVATE src/main.cpp)

###INCLUDING DIRECTORIES
###include for location where the header file searches
include_directories(include)
include(GoogleTest)

###Testing Code
### building the testing executable file
add_executable(RGBATests)
target_include_directories(RGBATests PRIVATE include)
target_sources(RGBATests PRIVATE tests/RGBATests.cpp)
###Finding and Configuring External Packages:
find_package(GTest CONFIG REQUIRED)

###TESTING CONFIGURATION
target_link_libraries(RGBATests PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(RGBATests)

