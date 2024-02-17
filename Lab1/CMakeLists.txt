cmake_minimum_required(VERSION 3.28)

# set( CMAKE_CXX_COMPILER "/usr/bin/g++" )
# set( CMAKE_C_COMPILER "/usr/bin/gcc" )

project(week-one-lab VERSION 1.0.0)
# message("Hello World")
add_executable(hello_world)
# target_sources(hello_world PRIVATE helloWorld.cpp)
target_sources(hello_world PRIVATE src/hello.cpp)
target_sources(hello_world PRIVATE src/name.cpp)
target_include_directories(hello_world PRIVATE include)