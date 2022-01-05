cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Crystal)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)

add_subdirectory(src)
add_subdirectory(test)
