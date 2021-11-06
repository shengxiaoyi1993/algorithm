

cmake_minimum_required (VERSION 3.0.2)
project (mini_path_sum VERSION 1.0)
set( CMAKE_CXX_FLAGS "-std=c++11" )
add_executable(${PROJECT_NAME} "../src/main.cpp""../src/solution.cpp")
set( CMAKE_BUILD_TYPE Debug )
